/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manu <manu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 13:14:19 by mruiz-sa          #+#    #+#             */
/*   Updated: 2022/09/07 22:09:07 by manu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft.h"
#include "error.h"

#include <readline/readline.h>

char	*ft_read(t_mini *state)
{
	get_prompt(state->envp, &state->prompt);
	state->readline = readline(state->prompt.prompt);
	if (!state->readline)
		exit_without_error(state);
	// if (ft_strlen(state->readline))
	// 	add_history(state->readline);
	ft_lexer(state->readline, ' ');
	// lexer converts state->readline into tokens (t_token in minishell.h)
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
		exit_without_error(state);
	return (state->readline);
}
