/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manu <manu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 13:14:19 by mruiz-sa          #+#    #+#             */
/*   Updated: 2022/09/03 20:32:44 by manu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft.h"
#include "error.h"

#include <readline/readline.h>

char	*ft_read(t_mini *state)
{
	get_prompt(state->envp, &state->prompt);
	state->readline = readline(state->prompt.prompt);
	free_prompt(&state->prompt);
	if (!ft_strncmp(state->readline, "exit", 4))
		exit_without_error(state);
	return (state->readline);
}