/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manu <manu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 13:14:19 by mruiz-sa          #+#    #+#             */
/*   Updated: 2022/10/18 21:03:46 by manu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft.h"
#include "error.h"

#include <readline/readline.h>
#include <readline/history.h>

char	*ft_read(t_mini *state)
{
	get_prompt(state->envp, &state->prompt);
	state->readline = readline(state->prompt.prompt);
	if (!state->readline)
		exit_without_error_check_leaks(state);
	if (!ft_strncmp(state->readline, "exit", 4))
		exit_without_error_check_leaks(state);
	if (ft_strlen(state->readline))
	{
		add_history(state->readline);
		ft_lexer(state->readline, state);
	}
	free_prompt(&state->prompt);
	return (state->readline);
}
