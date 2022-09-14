/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy_until.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manu <manu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 17:14:58 by mruiz-sa          #+#    #+#             */
/*   Updated: 2022/09/14 21:52:52 by manu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"
#include "libft.h"

char	*ft_strcpy_until(char *str, char until)
{
	char	*newstr;
	int		i;

	newstr = ft_strdup(str);
	if (!newstr)
		exit_with_memory_error();
	i = 0;
	while (newstr[i])
	{
		if (newstr[i] == until)
		{
			newstr[i] = '\0';
			break ;
		}
		i++;
	}
	return (newstr);
}
