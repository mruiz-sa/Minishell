/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_type.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manu <manu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 19:20:15 by manu              #+#    #+#             */
/*   Updated: 2022/10/11 19:45:05 by manu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_token_type	get_token_type(char *str)
{
	t_token_type	type;

	type = TK_NONE;
	if (str && *str == '|')
		type = TK_PIPE;
	else if (str && *str == '>' && *(str + 1) == '>')
		type = TK_GREATGREAT;
	else if (str && *str == '>')
		type = TK_GREAT;
	else if (str && *str == '<')
		type = TK_LESS;
	else if (str && *str == '&')
		type = TK_AMP;
	return (type);
}

int	is_token_redirection(t_token_type type)
{
	if (type == TK_GREAT || type == TK_GREATGREAT || type == TK_LESS)
		return (1);
	return (0);
}
