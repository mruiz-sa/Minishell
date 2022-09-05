/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manu <manu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 13:01:18 by mruiz-sa          #+#    #+#             */
/*   Updated: 2022/09/05 17:03:16 by manu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "minishell.h"
#include "error.h"
#include "state.h"
#include "signals.h"

int	main(int argc, char *argv[], char **envp)
{
	if (!init_state(&g_state, argc, argv, envp))
		return (exit_with_error("Error initializing", &g_state));
	setup_kill_signal_handler(on_kill_signal_action_received);
	while (1)
	{
		ft_read(&g_state);
		free(g_state.readline);
		g_state.readline = NULL;
	}
	return (exit_without_error(&g_state));
}
