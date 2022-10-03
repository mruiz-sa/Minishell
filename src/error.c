/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manugarc <manugarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 16:19:49 by manu              #+#    #+#             */
/*   Updated: 2022/10/03 20:46:55 by manugarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

#include "minishell.h"
#include "state.h"
#include "error.h"

static void	exit_with_code(int code)
{
	free_state(&g_state);
	// system("Leaks minishell");
	exit(code);
}

int	exit_with_error(char *message_error)
{
	printf("%s", message_error);
	exit_with_code(ERROR_GENERIC);
	return (0);
}

int	exit_with_memory_error(void)
{
	return (exit_with_error("Not enough memory"));
}

int	exit_without_error(void)
{
	exit_with_code(ERROR_NONE);
	return (0);
}
