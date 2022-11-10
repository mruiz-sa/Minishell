/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_is.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manugarc <manugarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 20:02:50 by manu              #+#    #+#             */
/*   Updated: 2022/11/10 19:37:44 by manugarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "ft_strcpy_until.h"
#include "malloc.h"

int	is_space(char c)
{
	if (c == ' ' || c == '\r' || c == '\t'
		|| c == '\v' || c == '\f' || c == '\n')
		return (1);
	return (0);
}

int	is_quote(char c)
{
	if (c == '\"' || c == '\'')
		return (1);
	return (0);
}

int	is_arg_breaking_char(char c)
{
	if (is_space(c) || is_quote(c) || c == '|' || c == '>'
		|| c == '<' || c == '&')
		return (1);
	return (0);
}
