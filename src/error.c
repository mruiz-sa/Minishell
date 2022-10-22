/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manugarc <manugarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 16:19:49 by manu              #+#    #+#             */
/*   Updated: 2022/10/22 12:52:28 by manugarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

#include "minishell.h"
#include "state.h"
#include "error.h"

static void	exit_with_code(t_mini *state, int code, int check_for_leaks)
{
	(void)check_for_leaks;
	free_state(state);
	// if (check_for_leaks)
	// 	system("Leaks minishell");
	exit(code);
}

int	exit_with_error(t_mini *state, char *message_error)
{
	printf("%s", message_error);
	exit_with_code(state, ERROR_GENERIC, 0);
	return (0);
}

int	exit_with_memory_error(t_mini *state)
{
	return (exit_with_error(state, "Not enough memory"));
}

int	exit_without_error(t_mini *state)
{
	exit_with_code(state, ERROR_NONE, 0);
	return (0);
}

int	exit_without_error_check_leaks(t_mini *state)
{
	exit_with_code(state, ERROR_NONE, 1);
	return (0);
}
