/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruiz-sa <mruiz-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 10:50:47 by mruiz-sa          #+#    #+#             */
/*   Updated: 2022/04/16 12:21:15 by mruiz-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_start(const char *set, const char *s1)
{
	size_t	i;

	i = 0;
	while (s1[i])
	{
		if (ft_strchr(set, s1[i]) == 0)
			return (i);
		i++;
	}
	return (i);
}

static size_t	ft_end(const char *set, const char *s1)
{
	size_t	len;
	size_t	i;

	len = ft_strlen(s1);
	i = 0;
	while (i < len)
	{
		if (ft_strchr(set, s1[len - i - 1]) == 0)
			return (i);
		i++;
	}
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	len;
	size_t	start;
	size_t	end;
	char	*str;

	if (!s1 || !set)
		return (NULL);
	len = ft_strlen(s1);
	start = ft_start(set, s1);
	end = len - ft_end(set, s1);
	if (start < end)
		return (ft_substr(s1, start, end - start));
	str = malloc(1);
	str[0] = '\0';
	return (str);
}
