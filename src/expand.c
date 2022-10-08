/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manugarc <manugarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 10:19:01 by manugarc          #+#    #+#             */
/*   Updated: 2022/10/08 12:52:15 by manugarc         ###   ########.fr       */
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
		if (token->type == TK_CMD)
			token->str = path_to_absolute(token->str, state);
		else if (token->type == TK_ARG && token->str[0] != '\'')
			token->str = expand_env_str(token->str, state);
		tokens = tokens->next;
	}
}
