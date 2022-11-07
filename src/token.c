/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manu <manu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 17:14:58 by mruiz-sa          #+#    #+#             */
/*   Updated: 2022/11/07 19:21:14 by manu             ###   ########.fr       */
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

static	char	*set_token_str(t_token *token, char *str)
{
	char	quote;

	quote = *str;
	if (quote == '\'')
		token->single_quote = 1;
	else if (quote == '\"')
		token->double_quote = 1;
	if (is_token_redirection(token->type))
	{
		token->str = token_type_to_str(token->type);
		return (skip_token_str(str, token->type));
	}
	else
		token->str = copy_enclosed_str(str);
	return (skip_enclosed_str(str));
}

static char	*create_token(t_list **tokens, char *str, t_token_type type)
{
	t_token	*token;
	char	quote;

	str = skip_spaces(str);
	quote = *str;
	token = ft_malloc(sizeof(t_token));
	token->type = type;
	str = set_token_str(token, str);
	if (token->type != TK_NONE)
	{
		ft_lstadd_back(tokens, ft_lstnew(token));
		if (*str && is_token_redirection(token->type))
			str = create_token(tokens, str, TK_ARG);
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
			str = create_token(&tokens, str, get_token_type(str));
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
	}
	return (tokens);
}

void	display_tokens(t_list	*tokens)
{
	t_token	*token;

	while (tokens)
	{
		token = get_token(tokens);
		printf("Token is type %d, ignore (%d), str = [%s]\n", token->type
			, token->ignore, token->str);
		if (token->single_quote)
			printf("Token was single quoted\n");
		if (token->double_quote)
			printf("Token was double quoted\n");
		tokens = tokens->next;
	}
}

static int	validate_consecutive_tokens(t_token *token, t_token *prev)
{
	if (!token)
		return (0);
	if (!prev)
		return (1);
	if (is_token_redirection(prev->type))
	{
		if (is_token_redirection(token->type))
			return (0);
		else if (token->type == TK_ARG && !ft_strncmp(token->str, "|", 2))
			return (0);
	}
	return (1);
}

static int	validate_redirection(t_token *token, t_token *next)
{
	if (!token || !next)
		return (0);
	if (!ft_strlen(next->str) || !ft_strncmp(next->str, "|", 1))
		return (0);
	return (1);
}

static int	validate_token(t_token *token, t_token *next, t_token *prev)
{
	if (!token)
		return (0);
	if (is_token_redirection(token->type) && token->type != TK_LESSLESS)
		return (validate_redirection(token, next));
	if (!prev && (token->type == TK_AMP || token->type == TK_PIPE))
		return (0);
	return (1);
}

int	validate_syntax_tokens(t_list *tokens)
{
	t_token	*token;
	t_token	*prev;

	if (!ft_lstsize(tokens))
		return (0);
	token = NULL;
	prev = NULL;
	while (tokens)
	{
		prev = token;
		token = get_token(tokens);
		if (!validate_token(token, get_token(tokens->next), prev))
			return (0);
		if ((token->type == TK_PIPE || token->type == TK_AMP)
			&& ft_lstsize(tokens) == 1)
			return (0);
		if (!validate_consecutive_tokens(token, prev))
			return (0);
		if (token && token->type == TK_ARG)
		{
			if (!ft_strlen(token->str))
				token->ignore = 1;
		}
		tokens = tokens->next;
	}
	return (1);
}
