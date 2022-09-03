/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruiz-sa <mruiz-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 16:22:30 by manu              #+#    #+#             */
/*   Updated: 2022/09/03 12:55:51 by mruiz-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>

#include "minishell.h"

int	init_state(t_mini *state, int argc, char *argv[], char **envp)
{
	(void) argc;
	(void) argv;
	memset(state, 0, sizeof(t_mini));
	state->envp = envp;
	return (1);
}

int	free_state(t_mini *state)
{
	if (state->prompt.pwd)
		free(state->prompt.pwd);
	memset(state, 0, sizeof(t_mini));
	return (1);
}

int	free_prompt(t_prompt *prompt)
{
	free(prompt->prompt);
	free(prompt->user);
	free(prompt->pwd);
	memset(prompt, 0, sizeof(t_prompt));
	return (1);
}
