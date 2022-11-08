/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manu <manu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 20:02:50 by manu              #+#    #+#             */
/*   Updated: 2022/11/08 19:00:01 by manu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "ft_strcpy_until.h"
#include "malloc.h"

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

int	is_arg_breaking_char(char c)
{
	if (is_space(c) || is_quote(c) || c == '|' || c == '>'
		|| c == '<' || c == '&')
		return (1);
	return (0);
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
		sanitized = ft_strcpy_until_quoted(sanitized);
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
		str = skip_until_char_quoted(str + 1);
	return (str);
}

char	*copy_escaped_str(char *str)
{
	int		escape;
	char	*escaped;
	int		len;
	int		i;

	i = 0;
	len = ft_strlen(str);
	escaped = (char *)ft_malloc(len + 1);
	escape = 1;
	while (str && *str)
	{
		if (*str == '\\' && escape)
			escape = 0;
		else
		{
			if (*str == '\\')
				escape = 1;
			escaped[i] = *str;
			i++;
		}
		str++;
	}
	escaped[i] = '\0';
	return (escaped);
}

char	*ft_str_tolower(char *str)
{
	char	*aux;

	aux = str;
	while (str && *str)
	{
		*str = ft_tolower(*str);
		str++;
	}
	return (aux);
}
