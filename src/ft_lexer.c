/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lexer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manu <manu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 17:14:58 by mruiz-sa          #+#    #+#             */
/*   Updated: 2022/09/09 18:55:21 by manu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "error.h"
#include "malloc.h"

#include <stdio.h>
#include <stdlib.h>

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
	int		n_words;
	t_token	*tokens;

	n_words = ft_count_words(str, c);
	printf("%d\n", n_words);
	tokens = lxr_get_tokens(str);
	if (tokens)
		free(tokens);
	return (0);
}

//
//  lexer converts state->readline into array of tokens (t_token in minishell.h)
// 		quick test: line = "ls -a a* | grep test > outfile.txt"
// 		token = ls, type cmd
// 		token = -a, type arg
// 		token = a*, type arg (expandable wildcard)
// 		token = |, type pipe (fork process)
// 		token = grep, type cmd
// 		token = test, arg
// 		token = >, type great (redirection)
// 
t_token	*lxr_get_tokens(char const *str)
{
	t_token	*tokens;
	int		n_tokens;
	int		i;

	n_tokens = ft_count_words(str, ' ');
	tokens = ft_malloc(n_tokens * sizeof(t_token));
	i = -1;
	while (i++ < n_tokens)
	{
		tokens[i].type = TK_CMD;
	}
	return (tokens);
}
