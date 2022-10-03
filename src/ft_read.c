/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manugarc <manugarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 13:14:19 by mruiz-sa          #+#    #+#             */
/*   Updated: 2022/10/03 21:08:26 by manugarc         ###   ########.fr       */
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
		exit_without_error(state);
	if (ft_strlen(state->readline))
	{
		add_history(state->readline);
		pid = fork();
		if (pid == -1)
			perror("ERROR");
		if (pid == 0)
			exec_cmd(state->readline, state);
		else
			waitpid(pid, NULL, 0);
		ft_lexer(state->readline);
	}
	free_prompt(&state->prompt);
	if (!ft_strncmp(state->readline, "exit", 4))
		exit_without_error(state);
	return (state->readline);
}
