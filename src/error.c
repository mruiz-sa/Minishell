/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manu <manu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 16:19:49 by manu              #+#    #+#             */
/*   Updated: 2022/10/15 22:20:06 by manu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

#include "minishell.h"
#include "state.h"
#include "error.h"

static void	exit_with_code(t_mini *state, int code)
{
	free_state(state);
	if (!code)
		system("Leaks minishell");
	exit(code);
}

int	exit_with_error(t_mini *state, char *message_error)
{
	printf("%s", message_error);
	exit_with_code(state, ERROR_GENERIC);
	return (0);
}

int	exit_with_memory_error(t_mini *state)
{
	return (exit_with_error(state, "Not enough memory"));
}

int	exit_without_error(t_mini *state)
{
	exit_with_code(state, ERROR_NONE);
	return (0);
}
