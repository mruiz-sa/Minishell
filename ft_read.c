/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruiz-sa <mruiz-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 13:14:19 by mruiz-sa          #+#    #+#             */
/*   Updated: 2022/09/03 12:17:10 by mruiz-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft.h"
#include "error.h"

#include <readline/readline.h>

char	*ft_read(t_mini *state, char **envp)
{
	t_prompt	prompt;

	get_prompt(envp, &prompt);
	state->readline = readline(prompt.prompt);
	if (!ft_strncmp(state->readline, "exit", 4))
	{
		free_prompt(&prompt);
		exit_without_error(state);
	}
	return (state->readline);
}
