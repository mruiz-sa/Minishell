/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_expand.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manu <manu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 10:19:01 by manugarc          #+#    #+#             */
/*   Updated: 2022/10/31 18:05:58 by manu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "token.h"
#include "env.h"
#include "path.h"
#include "str.h"

static int	is_expandable_arg(char *str)
{
	int		n_escapes;
	int		mod;

	mod = 0;
	if (!ft_strchr(str, '$'))
		return (0);
	n_escapes = 0;
	while (str && *str)
	{
		if (*str == '\\')
			n_escapes++;
		else
		{
			if (*str == '$')
			{
				mod = n_escapes % 2;
				if (!mod)
					return (1);
			}
			n_escapes = 0;
		}
		str++;
	}
	return (0);
}

void	expand_token_strings(t_list *tokens, t_mini *state)
{
	t_token	*token;

	while (tokens)
	{
		token = get_token(tokens);
		if (!token->ignore)
		{
			if (token->type == TK_CMD)
				token->str = path_to_absolute(token->str, state);
			else if (token->type == TK_ARG && !token->single_quote)
			{
				while (is_expandable_arg(token->str))
					token->str = expand_env_str(token->str, state);
			}
		}
		tokens = tokens->next;
	}
}
