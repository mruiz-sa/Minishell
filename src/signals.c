/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manu <manu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 17:09:41 by manugarc          #+#    #+#             */
/*   Updated: 2022/09/07 19:56:03 by manu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <readline/readline.h>

#include "signals.h"
#include "libft.h"
#include "state.h"

/**
 * @brief printf("\33[2K\r"); is understood by most shells, but it 
 * is a workaround using VT100 Escape Codes.
 * 
 * Code should be;
 * 
 * 		rl_on_new_line();
 * 		rl_replace_line("", 0);
 * 		rl_redisplay();
 * 
 * @param signum 
 */
void	on_kill_signal_action_received(int signum)
{
	if (signum == SIGINT)
	{
		// printf("\33[2K\r");
		// write(STDERR_FILENO, "\n", ft_strlen("\n"));
		// write(STDERR_FILENO, g_state.prompt.prompt,
		// 	ft_strlen(g_state.prompt.prompt));
		write(1, "\n", 1);
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
}

void	setup_kill_signal_handler(void (*sa_handler_fn)(int))
{
	struct sigaction	signal_action;

	signal_action.sa_handler = sa_handler_fn;
	signal_action.sa_flags = 0;
	sigemptyset(&signal_action.sa_mask);
	sigaddset(&signal_action.sa_mask, SIGINT);
	sigaction(SIGINT, &signal_action, NULL);
}
