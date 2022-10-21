/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manu <manu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 20:02:50 by manu              #+#    #+#             */
/*   Updated: 2022/10/21 19:21:24 by manu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*join_and_free(char *s1, char *s2)
{
	char	*joined;

	joined = ft_strjoin(s1, s2);
	free(s1);
	free(s2);
	return (joined);
}

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
	if (type == TK_PIPE && *str == '<')
		return (str + 1);
	if (type == TK_AMP && *str == '<')
		return (str + 1);
	return (str);
}
