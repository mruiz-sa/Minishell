/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruiz-sa <mruiz-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 13:01:18 by mruiz-sa          #+#    #+#             */
/*   Updated: 2022/09/02 14:18:02 by mruiz-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "error.h"
#include "state.h"

int	main(int argc, char *argv[], char **envp)
{
	t_mini	state;

	if (!init_state(&state, argc, argv))
		return (exit_with_error("Error initializing", &state));
	while (1)
		ft_read(&state, envp);
	free_state(&state);
	return (0);
}
