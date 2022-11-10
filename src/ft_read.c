/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manugarc <manugarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 13:14:19 by mruiz-sa          #+#    #+#             */
/*   Updated: 2022/11/10 19:25:53 by manugarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"
#include "command_table.h"
#include "libft.h"
#include "minishell.h"
#include "token.h"
#include "token_expand.h"
#include "token_free.h"
#include "token_validate.h"
#include "token_sanitize.h"

#include <readline/readline.h>
#include <readline/history.h>

// echo hi | cd test | pwd >> outfile.txt > outfile2.txt < infile &
static void	process_readline(char *str, t_mini *state)
{
	t_list	*tokens;
	t_cmd	*cmd_table;

	tokens = str_to_tokens(str);
	if (!tokens)
		return ;
	expand_token_strings(tokens, state);
	sanitize_token_strings(tokens, state);
	if (validate_syntax_tokens(tokens))
	{
		cmd_table = tokens_to_cmd_table(tokens);
		exec_cmd_table(cmd_table, state);
		free_cmd_table(cmd_table);
	}
	else
		printf("syntax error unexpected token\n");
	free_tokens(tokens);
}

char	*ft_read(t_mini *state)
{
	get_prompt(state->envp, &state->prompt);
	state->readline = readline(state->prompt.prompt);
	if (!state->readline)
	{
		printf("exit\n");
		exit_without_error(state);
	}
	if (ft_strlen(state->readline))
	{
		add_history(state->readline);
		process_readline(state->readline, state);
	}
	free_prompt(&state->prompt);
	return (state->readline);
}
