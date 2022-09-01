/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruiz-sa <mruiz-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 11:32:23 by mruiz-sa          #+#    #+#             */
/*   Updated: 2022/04/14 17:30:30 by mruiz-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	c;

	if (needle[0] == '\0')
		return ((char *)haystack);
	c = 0;
	while (c < len && haystack[c])
	{
		i = 0;
		while (c < len && needle[i] && haystack[c] && needle[i] == haystack[c])
		{
			++i;
			++c;
		}
		if (needle[i] == '\0')
			return ((char *)&haystack[c - i]);
		c = c - i + 1;
	}
	return (0);
}
