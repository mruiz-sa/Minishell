/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_sanitize.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manu <manu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 10:19:01 by manugarc          #+#    #+#             */
/*   Updated: 2022/10/31 18:53:37 by manu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "str.h"
#include "token.h"

void	sanitize_token_strings(t_list *tokens, t_mini *state)
{
	t_token	*token;
		// char	*aux;

	(void)state;
	while (tokens)
	{
		token = get_token(tokens);
		// TODO: This fixes echo $PWD''
		// if (token->type == TK_ARG && !token->ignore)
		// {
		// 	if (ft_strchr(token->str, '\'') || ft_strchr(token->str, '\"'))
		// 	{
		// 		aux = token->str;
		// 		token->str = copy_enclosed_str(token->str);
		// 		if (aux)
		// 			free(aux);
		// 	}
		// }
		tokens = tokens->next;
	}
}
