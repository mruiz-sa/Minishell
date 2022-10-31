/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy_until.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manu <manu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 17:14:58 by mruiz-sa          #+#    #+#             */
/*   Updated: 2022/10/31 16:45:25 by manu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"
#include "libft.h"

char	*ft_strcpy_until_quoted(char *str, char until)
{
	char	*newstr;
	int		i;
	int		single_quotes;
	int		double_quotes;
	int		dir;

	dir = 1;
	single_quotes = 0;
	double_quotes = 0;
	newstr = ft_strdup(str);
	if (!newstr)
		exit_with_memory_error(NULL);
	i = 0;
	while (newstr[i])
	{
		if (newstr[i] == '\'')
			single_quotes += dir;
		if (newstr[i] == '\"')
			double_quotes += dir;
		if (newstr[i] == ' ')
			dir *= -1;
		if (newstr[i] == until && !single_quotes && !double_quotes)
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
