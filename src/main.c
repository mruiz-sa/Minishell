/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manu <manu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 13:01:18 by mruiz-sa          #+#    #+#             */
/*   Updated: 2022/09/24 15:05:44 by manu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

#include "minishell.h"
#include "error.h"
#include "state.h"
#include "signals.h"

int	main(int argc, char *argv[], char **envp)
{
	t_mini		state;

	if (!init_state(&state, argc, argv, envp))
		return (exit_with_error(&state, "Error initializing"));
	setup_kill_signal_handler(on_kill_signal_action_received);
	while (1)
	{
		ft_read(&state);
		free(state.readline);
		state.readline = NULL;
	}
	return (exit_without_error(&state));
}
