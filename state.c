/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manu <manu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 16:22:30 by manu              #+#    #+#             */
/*   Updated: 2022/09/01 19:44:04 by manu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>

#include "minishell.h"

int	init_state(t_mini *state, int argc, char *argv[])
{
	(void) argc;
	(void) argv;
	memset(state, 0, sizeof(t_mini));
	return (1);
}

int	free_state(t_mini *state)
{
	memset(state, 0, sizeof(t_mini));
	return (1);
}
