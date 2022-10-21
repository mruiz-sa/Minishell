/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manu <manu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 17:14:58 by mruiz-sa          #+#    #+#             */
/*   Updated: 2022/10/21 19:21:37 by manu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

#include "env.h"
#include "error.h"
#include "libft.h"
#include "minishell.h"
#include "malloc.h"
#include "path.h"
#include "str.h"
#include "token_type.h"

static	void	set_token_str(t_token *token, char *str)
{
	char	quote;

	quote = *str;
	if (token->type == TK_ARG && (*str == '\'' || *str == '\"'))
		token->str = ft_strcpy_until(++str, quote);
	else if (is_token_redirection(token->type))
		token->str = token_type_to_str(token->type);
	else
		token->str = ft_strcpy_until(str, ' ');
	if (quote == '\'')
		token->single_quote = 1;
	else if (quote == '\"')
		token->double_quote = 1;
}

static char	*create_token(t_list **tokens, char *str, t_token_type type)
{
	t_token	*token;
	char	quote;

	quote = *str;
	str = skip_spaces(str);
	token = ft_malloc(sizeof(t_token));
	if (type != TK_NONE)
		token->type = type;
	else
		token->type = get_token_type(str);
	set_token_str(token, str);
	if (token->type != TK_NONE)
	{
		ft_lstadd_back(tokens, ft_lstnew(token));
		if (is_token_redirection(token->type))
		{
			str = skip_token_str(str, token->type);
			str = create_token(tokens, str, TK_ARG);
		}
		else if (token->type == TK_ARG && (quote == '\'' || quote == '\"'))
			str = find_char(++str, quote);
	}
	else
		free(token);
	return (str);
}

static void	free_node_content(void *content)
{
	t_token	*token;

	token = content;
	if (!token)
		return ;
	if (token->str != NULL)
		free(token->str);
	free(token);
}

void	free_tokens(t_list *tokens)
{
	if (!tokens)
		return ;
	ft_lstclear(&tokens, free_node_content);
}

t_token	*get_token(t_list *token_node)
{
	if (token_node && token_node->content)
		return ((t_token *)token_node->content);
	return (NULL);
}

/* echo hi | cd test | pwd >> outfile.txt > outfile2.txt < infile & */

t_list	*str_to_tokens(char *str)
{
	t_list	*tokens;
	int		can_be_cmd;

	tokens = NULL;
	can_be_cmd = 1;
	while (str && *str)
	{
		str = skip_spaces(str);
		if (*str == '|' || *str == '>' || *str == '<' || *str == '&')
		{
			str = create_token(&tokens, str, TK_NONE);
			can_be_cmd = 1;
		}
		else if (*str)
		{
			if (can_be_cmd)
				str = create_token(&tokens, str, TK_CMD);
			else if (*str)
				str = create_token(&tokens, str, TK_ARG);
			can_be_cmd = 0;
		}
		str = find_char(str, ' ');
	}
	return (tokens);
}

void	display_tokens(t_list	*tokens)
{
	t_token	*token;

	while (tokens)
	{
		token = get_token(tokens);
		printf("Token is type %d, str = %s\n", token->type, token->str);
		if (token->single_quote)
			printf("Token was single quoted\n");
		if (token->double_quote)
			printf("Token was double quoted\n");
		tokens = tokens->next;
	}
}

int	validate_syntax_tokens(t_list *tokens)
{
	(void)tokens;
	return (1);
}
