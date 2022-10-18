/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_env.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manu <manu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 21:16:07 by manu              #+#    #+#             */
/*   Updated: 2022/10/18 21:02:49 by manu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "array.h"
#include "command.h"
#include "minishell.h"

int	run_builtin_env(t_simple_cmd	*cmd, t_mini *state)
{
	char	**envp;
	int		i;

	(void)cmd;
	envp = state->envp;
	i = 0;
	while (envp[i])
	{
		printf("%s\n", envp[i++]);
	}
	return (1);
}
