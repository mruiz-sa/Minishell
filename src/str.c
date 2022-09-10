/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manu <manu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 20:02:50 by manu              #+#    #+#             */
/*   Updated: 2022/09/10 20:02:53 by manu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*skip_char(char *str, char c)
{
	while (str && *str && *str == c)
	{
		str++;
	}
	return (str);
}

char	*find_char(char *str, char c)
{
	while (str && *str && *str != c)
	{
		str++;
	}
	if (*str == c)
		str++;
	return (str);
}

int	check_quotes(char **str, char c)
{
	if (**str == c)
	{
		(*str) = find_char(++(*str), c);
		return (1);
	}
	return (0);
}
