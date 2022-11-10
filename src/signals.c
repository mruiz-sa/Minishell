/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manugarc <manugarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 17:09:41 by manugarc          #+#    #+#             */
/*   Updated: 2022/11/10 20:05:41 by manugarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <readline/readline.h>

#include "signals.h"
#include "libft.h"
#include "state.h"

static void	on_sigint_signal(int signum)
{
	if (signum == SIGINT)
	{
		write(1, "\n", 1);
		rl_replace_line("", 0);
		rl_on_new_line();
		rl_redisplay();
		g_exec_ret = 1;
	}
}

static void	on_sigquit_signal(int signum)
{
	if (signum == SIGQUIT)
		write(1, "Quit: 3", 7);
}

static	void	setup_signal(void (*sa_handler_fn)(int), int signum)
{
	struct sigaction	signal_action;

	ft_memset(&signal_action, 0, sizeof(struct sigaction));
	signal_action.sa_handler = sa_handler_fn;
	signal_action.sa_flags = 0;
	sigemptyset(&signal_action.sa_mask);
	sigaddset(&signal_action.sa_mask, signum);
	sigaction(signum, &signal_action, NULL);
}

void	set_parent_signals(void)
{
	setup_signal(on_sigint_signal, SIGINT);
	signal(SIGQUIT, SIG_IGN);
}

void	set_sigquit_signal(void)
{
	setup_signal(on_sigquit_signal, SIGQUIT);
}
