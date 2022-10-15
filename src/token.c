/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manugarc <manugarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 17:14:58 by mruiz-sa          #+#    #+#             */
/*   Updated: 2022/10/15 12:52:53 by manugarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "error.h"
#include "malloc.h"
#include "libft.h"
#include "str.h"
#include "env.h"
#include "path.h"
#include "token_type.h"

#include <stdio.h>
#include <stdlib.h>

char	*get_token_str(char *str, t_token_type type)
{
	char	quote;

	if (type == TK_ARG && (*str == '\'' || *str == '\"'))
	{
		quote = *str;
		return (ft_strcpy_until(++str, quote));
	}
	else if (type == TK_CMD)
		return (ft_strcpy_until(str, ' '));
	return (ft_strcpy_until(str, ' '));
}

static char	*create_token(t_list	**tokens, char *str, t_token_type type)
{
	t_token	*token;

	str = skip_spaces(str);
	token = ft_malloc(sizeof(t_token));
	token->str = get_token_str(str, type);
	if (type != TK_NONE)
		token->type = type;
	else
		token->type = get_token_type(str);
	if (token->type != TK_NONE)
	{
		ft_lstadd_back(tokens, ft_lstnew(token));
		if (token->type == TK_GREAT || token->type == TK_LESS)
		{
			str = find_char(str, ' ');
			str = create_token(tokens, str, TK_ARG);
		}
	}
	else
		free(token);
	str = find_char(str, ' ');
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
			if (*str == '|')
				can_be_cmd = 1;
			str++;
			if (*str == '>' || *str == '<')
				str++;
		}
		else
		{
			if (can_be_cmd)
			{
				str = create_token(&tokens, str, TK_CMD);
				can_be_cmd = 0;
			}
			else if (*str == '\'')
			{
				str = create_token(&tokens, str, TK_ARG);
				can_be_cmd = 0;
				str = find_char(++str, '\'');
			}
			else if (*str == '\"')
			{
				str = create_token(&tokens, str, TK_ARG);
				can_be_cmd = 0;
				str = find_char(++str, '\"');
			}
			else if (*str)
			{
				str = create_token(&tokens, str, TK_ARG);
				can_be_cmd = 0;
			}
			str = find_char(str, ' ');
		}
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
		tokens = tokens->next;
	}
}

int	validate_syntax_tokens(t_list *tokens)
{
	(void)tokens;
	return (1);
}
