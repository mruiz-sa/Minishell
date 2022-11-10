/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_validate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manugarc <manugarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 17:14:58 by mruiz-sa          #+#    #+#             */
/*   Updated: 2022/11/10 20:53:10 by manugarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "token.h"
#include "token_type.h"

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
	if (is_token_redirection(token->type))
		return (validate_redirection(token, next));
	if (!prev && (token->type == TK_AMP || token->type == TK_PIPE))
		return (0);
	return (1);
}

int	validate_syntax_tokens(t_list *tokens)
{
	t_token	*token;
	t_token	*prev;
	int		size;

	size = ft_lstsize(tokens);
	if (!size)
		return (0);
	token = NULL;
	prev = NULL;
	while (tokens)
	{
		prev = token;
		token = get_token(tokens);
		if (!validate_token(token, get_token(tokens->next), prev))
			return (0);
		if ((token->type == TK_PIPE || token->type == TK_AMP) && size == 1)
			return (0);
		if (!validate_consecutive_tokens(token, prev))
			return (0);
		if (token && token->type == TK_ARG && !ft_strlen(token->str))
				token->ignore = 1;
		tokens = tokens->next;
	}
	return (1);
}
