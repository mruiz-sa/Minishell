/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_expand.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manu <manu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 10:19:01 by manugarc          #+#    #+#             */
/*   Updated: 2022/10/31 16:48:42 by manu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "token.h"
#include "env.h"
#include "path.h"

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
				while (ft_strchr(token->str, '$'))
					token->str = expand_env_str(token->str, state);
			}
		}
		tokens = tokens->next;
	}
}
