/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manu <manu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 17:09:41 by manugarc          #+#    #+#             */
/*   Updated: 2022/09/03 20:51:35 by manu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

#include "signals.h"

void	on_kill_signal_action_received(int signum)
{
	if (signum == SIGINT)
	{
		printf("CTRL-C pressed. Send new line to STDINPUT?\n");
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
