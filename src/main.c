/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manu <manu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 13:01:18 by mruiz-sa          #+#    #+#             */
/*   Updated: 2022/09/09 18:55:37 by manu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

#include "minishell.h"
#include "error.h"
#include "state.h"
#include "signals.h"

void	new(struct s_simple_cmd *self, int argc, char **argv)
{
	self->argc = argc;
	self->argv = argv;
}

char	*get_argv(struct s_simple_cmd *self)
{
	return (self->argv[0]);
}

int	main(int argc, char *argv[], char **envp)
{
	t_simple_cmd	test;

	test.new = new;
	test.fn_test = get_argv;
	test.new(&test, argc, argv);
	printf("test fn in struct, ignore it, argv[0] = %s\n", test.fn_test(&test));
	if (!init_state(&g_state, argc, argv, envp))
		return (exit_with_error("Error initializing"));
	setup_kill_signal_handler(on_kill_signal_action_received);
	while (1)
	{
		ft_read(&g_state);
		free(g_state.readline);
		g_state.readline = NULL;
	}
	return (exit_without_error());
}
