/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_skip.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manugarc <manugarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 20:02:50 by manu              #+#    #+#             */
/*   Updated: 2022/11/10 19:37:26 by manugarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "ft_strcpy_until.h"
#include "malloc.h"
#include "str_is.h"

char	*skip_spaces(char *str)
{
	while (str && *str && is_space(*str))
		str++;
	return (str);
}

static char	*skip_until_char_quoted(char *str)
{
	while (str && *str)
	{
		if (is_arg_breaking_char(*str))
			break ;
		str++;
	}
	return (str);
}

static char	*skip_until_char(char *str, char c)
{
	while (str && *str && *str != c)
	{
		str++;
	}
	if (*str == c)
		str++;
	return (str);
}

char	*skip_token_str(char *str, t_token_type type)
{
	if (type == TK_GREAT && *str == '>')
		return (str + 1);
	if (type == TK_GREATGREAT && *str == '>')
		return (str + 2);
	if (type == TK_LESS && *str == '<')
		return (str + 1);
	if (type == TK_LESSLESS && *str == '<')
		return (str + 2);
	if (type == TK_PIPE && *str == '|')
		return (str + 1);
	if (type == TK_AMP && *str == '&')
		return (str + 1);
	return (str);
}

char	*skip_enclosed_str(char *str)
{
	if (!str || !*str)
		return (str);
	str = skip_spaces(str);
	if (is_quote(*str))
		str = skip_until_char(str + 1, *str);
	else
		str = skip_until_char_quoted(str + 1);
	return (str);
}
