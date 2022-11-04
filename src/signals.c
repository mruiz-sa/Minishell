/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manugarc <manugarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 17:09:41 by manugarc          #+#    #+#             */
/*   Updated: 2022/11/04 11:40:13 by manugarc         ###   ########.fr       */
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
static void	on_parent_signal(int signum)
{
	if (signum == SIGINT/* || signum == SIGQUIT*/)
	{
		write(1, "\n", 1);
		rl_replace_line("", 0);
		rl_on_new_line();
		rl_redisplay();
	}
}

static void	on_child_signal(int signum)
{
	if (signum == SIGQUIT)
		write(1, "Quit: 3", 7);
}

static	void	setup_kill_signal_handler(void (*sa_handler_fn)(int), int squit)
{
	struct sigaction	signal_action;

	signal_action.sa_handler = sa_handler_fn;
	signal_action.sa_flags = 0;
	sigemptyset(&signal_action.sa_mask);
	sigaddset(&signal_action.sa_mask, SIGINT);
	sigaction(SIGINT, &signal_action, NULL);
	if (squit)
	{
		sigaddset(&signal_action.sa_mask, SIGQUIT);
		sigaction(SIGQUIT, &signal_action, NULL);
	}
	else
		signal(SIGQUIT, SIG_IGN);
}

void	set_parent_signals(void)
{
	setup_kill_signal_handler(on_parent_signal, 0);
}

void	set_child_signals(void)
{
	setup_kill_signal_handler(on_child_signal, 1);
}

void	unset_signals(void)
{
	signal(SIGINT, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
}
