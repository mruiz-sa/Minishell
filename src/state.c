/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manugarc <manugarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 16:22:30 by manu              #+#    #+#             */
/*   Updated: 2022/11/04 14:08:23 by manugarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>

#include "minishell.h"
#include "array.h"

int	init_state(t_mini *state, int argc, char *argv[], char **envp)
{
	(void) argc;
	(void) argv;
	memset(state, 0, sizeof(t_mini));
	state->envp = duplicate_array(envp);
	return (1);
}

int	free_state(t_mini *state)
{
	if (!state)
		return (0);
	if (state->readline)
		free(state->readline);
	free_prompt(&state->prompt);
	free_array(state->envp);
	memset(state, 0, sizeof(t_mini));
	return (1);
}

int	free_prompt(t_prompt *prompt)
{
	if (prompt->prompt)
		free(prompt->prompt);
	if (prompt->pwd)
		free(prompt->pwd);
	memset(prompt, 0, sizeof(t_prompt));
	return (1);
}
