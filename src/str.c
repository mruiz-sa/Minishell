/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manu <manu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 20:02:50 by manu              #+#    #+#             */
/*   Updated: 2022/10/25 20:05:19 by manu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*join_and_free(char *s1, char *s2)
{
	char	*joined;

	joined = ft_strjoin(s1, s2);
	free(s1);
	free(s2);
	return (joined);
}

int	is_space(char c)
{
	if (c == ' ' || c == '\r' || c == '\t'
		|| c == '\v' || c == '\f' || c == '\n')
		return (1);
	return (0);
}

char	*skip_spaces(char *str)
{
	while (str && *str && is_space(*str))
		str++;
	return (str);
}

static int	is_quote(char c)
{
	if (c == '\"' || c == '\'')
		return (1);
	return (0);
}

char	*skip_until_char(char *str, char c)
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
	if (type == TK_PIPE && *str == '<')
		return (str + 1);
	if (type == TK_AMP && *str == '<')
		return (str + 1);
	return (str);
}

char	*copy_enclosed_str(char *str)
{
	char	*sanitized;
	char	*aux;

	if (!str || !*str)
		return (str);
	aux = ft_strdup(str);
	sanitized = ft_strtrim(aux, " ");
	free(aux);
	if (!sanitized || !*sanitized)
		return (sanitized);
	aux = sanitized;
	if (is_quote(*sanitized))
		sanitized = ft_strcpy_until(sanitized + 1, *sanitized);
	else
		sanitized = ft_strcpy_until(sanitized, ' ');
	free(aux);
	return (sanitized);
}

char	*skip_enclosed_str(char *str)
{
	if (!str || !*str)
		return (str);
	str = skip_spaces(str);
	if (is_quote(*str))
		str = skip_until_char(str + 1, *str);
	else
		str = skip_until_char(str + 1, ' ');
	return (str);
}
