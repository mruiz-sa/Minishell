/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lexer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manu <manu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 17:14:58 by mruiz-sa          #+#    #+#             */
/*   Updated: 2022/10/09 19:42:38 by manu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "error.h"
#include "malloc.h"
#include "token.h"
#include "command_table.h"
#include "str.h"
#include "expand.h"

#include <stdio.h>
#include <stdlib.h>

// echo hi | cd test | pwd >> outfile.txt > outfile2.txt < infile &
char	**ft_lexer(char *str, t_mini *state)
{
	t_list	*tokens;
	t_cmd	*cmd_table;

	tokens = str_to_tokens(str);
	// display_tokens(tokens);
	expand_token_strings(tokens, state);
	validate_syntax_tokens(tokens);
	// TODO: Mover esto a parser
	cmd_table = tokens_to_cmd_table(tokens);
	// display_cmd_table(cmd_table);
	exec_cmd_table(cmd_table, state);
	free_tokens(tokens);
	free_cmd_table(cmd_table);
	return (0);
}
