/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruiz-sa <mruiz-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 11:01:47 by mruiz-sa          #+#    #+#             */
/*   Updated: 2022/04/18 11:16:55 by mruiz-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_number_of_words(const char *s, char c)
{
	int	num_w;
	int	i;

	i = 0;
	num_w = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i])
			num_w++;
		while (s[i] != c && s[i])
			i++;
	}
	return (num_w);
}

char	**ft_splitter(const char *s, char c)
{
	int		i;
	int		j;
	int		start;
	int		len;
	char	**split;

	i = -1;
	j = 0;
	start = -1;
	len = ft_strlen(s);
	split = (char **) malloc((ft_number_of_words(s, c) + 1) * sizeof(char *));
	if (!split || sizeof(split) == 0)
		return (NULL);
	while (++i <= len)
	{
		if (s[i] != c && start < 0)
			start = i;
		else if (start >= 0 && (s[i] == c || i == len))
		{
			split[j++] = ft_substr(s, start, i - start);
			start = -1;
		}
	}
	split[j] = NULL;
	return (split);
}

char	**ft_split(char const *s, char c)
{
	if (!s)
		return (NULL);
	return (ft_splitter(s, c));
}
