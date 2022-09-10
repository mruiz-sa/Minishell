/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lexer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manu <manu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 17:14:58 by mruiz-sa          #+#    #+#             */
/*   Updated: 2022/09/10 20:06:36 by manu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "error.h"
#include "malloc.h"
#include "token.h"
#include "str.h"

#include <stdio.h>
#include <stdlib.h>

static int	ft_count_words(char *str, char c)
{
	int		num_w;

	num_w = 0;
	while (str && *str)
	{
		str = skip_char(str, c);
		if (*str == '|' || *str == '>' || *str == '<')
		{
			str++;
			num_w++;
		}
		else
		{
			if (check_quotes(&str, '\"')
				|| check_quotes(&str, '\'') || *str)
				num_w++;
			str = find_char(str, c);
		}
	}
	return (num_w);
}

char	**ft_lexer(char *str, char c)
{
	int		n_words;
	t_list	*tokens;
	t_list	*aux_to_free;
	t_token	*token;

	n_words = ft_count_words(str, c);
	printf("%d\n", n_words);
	tokens = str_to_tokens(str);
	aux_to_free = tokens;
	while (tokens)
	{
		token = get_token(tokens);
		tokens = tokens->next;
	}
	free_tokens(aux_to_free);
	return (0);
}
