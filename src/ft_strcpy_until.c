/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy_until.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manugarc <manugarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 17:14:58 by mruiz-sa          #+#    #+#             */
/*   Updated: 2022/11/10 19:36:11 by manugarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"
#include "libft.h"
#include "redirection.h"
#include "str.h"
#include "str_is.h"

char	*ft_strcpy_until_quoted(char *str)
{
	char	*newstr;
	int		i;

	newstr = ft_strdup(str);
	if (!newstr)
		exit_with_memory_error(NULL);
	i = 0;
	while (newstr[i])
	{
		if (is_arg_breaking_char(newstr[i]))
		{
			newstr[i] = '\0';
			break ;
		}
		i++;
	}
	return (newstr);
}

char	*ft_strcpy_until(char *str, char until)
{
	char	*newstr;
	int		i;

	newstr = ft_strdup(str);
	if (!newstr)
		exit_with_memory_error(NULL);
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
