/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lexer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruiz-sa <mruiz-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 17:14:58 by mruiz-sa          #+#    #+#             */
/*   Updated: 2022/09/06 18:36:11 by mruiz-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft.h"

#include<stdio.h>

static int	ft_count_words(const char *s, char c)
{
	int	i;
	int	num_w;

	i = 0;
	num_w = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] == '|' || s[i] == '>' || s[i] == '<')
		{
			i++;
			num_w++;
		}
		else
		{
			if (s[i] == '\"')
			{
				i++;
				while (s[i] != '\"')
					i++;
				i++;
				num_w++;
			}
			else if (s[i] == '\'')
			{
				i++;
				while (s[i] != '\'')
					i++;
				i++;
				num_w++;
			}
			else if (s[i])
				num_w++;
			while (s[i] != c && s[i])
				i++;
		}
	}
	return (num_w);
}

char	**ft_lexer(char const *str, char c)
{
	int	n_words;

	n_words = ft_count_words(str, c);
	printf("%d\n", n_words);
	return (0);
}
