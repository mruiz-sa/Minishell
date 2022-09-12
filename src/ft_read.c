/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruiz-sa <mruiz-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 13:14:19 by mruiz-sa          #+#    #+#             */
/*   Updated: 2022/09/12 14:09:31 by mruiz-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft.h"
#include "error.h"

#include <readline/readline.h>
#include <readline/history.h>

char	*ft_read(t_mini *state)
{
	pid_t	pid;

	get_prompt(state->envp, &state->prompt);
	state->readline = readline(state->prompt.prompt);
	if (!state->readline)
		exit_without_error();
	if (ft_strlen(state->readline))
	{
		add_history(state->readline);
		pid = fork();
		if (pid == -1)
			perror("ERROR");
		if (pid == 0)
			exec_cmd(state->readline, state);
		else
		{
			waitpid(pid, NULL, 0);
			ft_lexer(state->readline, ' ');
		}
	}
	// lexer string count n words
	// 		quick test: line = "ls -a a* | grep test > outfile.txt"
	//		8
	// lexer string y expandir variables entorno
	// lexer string to array (token)
	//		t_token[0] = 'ls'
	//		t_token[1] = '-a'
	// parser validate grammar, converts tokens into a command table (t_cmd in minishell.h)
	// convert state->readline into a command table
	// 		break state->readline into simple commands (t_simple_cmd in minishell.h)
	//		simple commands are separated by pipes
	//		per each command, expand variables and wildcards
	// execute the command table
	// 		for each command create a new process
	//		wait process. In "ls -a | wc", "wc" process should wait for "ls" to finish?
	free_prompt(&state->prompt);
	if (!ft_strncmp(state->readline, "exit", 4))
		exit_without_error();
	return (state->readline);
}
