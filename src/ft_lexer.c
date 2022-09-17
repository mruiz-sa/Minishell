/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lexer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manugarc <manugarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 17:14:58 by mruiz-sa          #+#    #+#             */
/*   Updated: 2022/09/17 13:19:32 by manugarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "error.h"
#include "malloc.h"
#include "token.h"
#include "command_table.h"
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

// echo hi | cd test | pwd >> outfile.txt > outfile2.txt < infile &
char	**ft_lexer(char *str, char c)
{
	int		n_words;
	t_list	*tokens;
	t_cmd	*cmd_table;

	n_words = ft_count_words(str, c);
	tokens = str_to_tokens(str);
	display_tokens(tokens);
	printf("\n");
	validate_syntax_tokens(tokens);
	cmd_table = tokens_to_cmd_table(tokens);
	display_cmd_table(cmd_table);
	free_tokens(tokens);
	free_cmd_table(cmd_table);
	return (0);
}
