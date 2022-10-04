/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruiz-sa <mruiz-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 20:02:50 by manu              #+#    #+#             */
/*   Updated: 2022/10/04 17:00:14 by mruiz-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*skip_spaces(char *str)
{
	while (str && *str && (*str == ' ' || *str == '\r'
			|| *str == '\t' || *str == '\v' || *str == '\f'
			|| *str == '\n'))
	{
		str++;
	}
	return (str);
}

char	*skip_char(char *str, char c)
{
	while (str && *str && *str == c)
	{
		str++;
	}
	return (str);
}

int	is_space(char c)
{
	if (c == ' ' || c == '\r' || c == '\t'
		|| c == '\v' || c == '\f' || c == '\n')
		return (1);
	return (0);
}

int	is_special_char(char c)
{
	if (c == ' ' || c == '\r' || c == '\t' || c == '\v' || c == '\f'
		|| c == '\n' || c == '|' || c == '>' || c == '<' || c == '&'
		|| c == '\'' || c == '\"')
		return (1);
	return (0);
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
