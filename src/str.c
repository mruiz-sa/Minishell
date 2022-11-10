/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manugarc <manugarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 20:02:50 by manu              #+#    #+#             */
/*   Updated: 2022/11/10 19:36:30 by manugarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "ft_strcpy_until.h"
#include "malloc.h"
#include "str_is.h"

char	*join_and_free(char *s1, char *s2)
{
	char	*joined;

	joined = ft_strjoin(s1, s2);
	free(s1);
	free(s2);
	return (joined);
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
