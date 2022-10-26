/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_exit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruiz-sa <mruiz-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 21:16:07 by manu              #+#    #+#             */
/*   Updated: 2022/10/26 19:26:46 by mruiz-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command.h"
#include "error.h"
#include "minishell.h"

int	run_builtin_exit(t_simple_cmd	*cmd, t_mini *state)
{
	int	i;

	i = 0;
	if (cmd->argc > 2)
	{
		printf("exit: too many arguments\n");
		state->exec_ret = 1;
	}
	else if (cmd->argc == 2)
	{
		while (cmd->argv[1][i])
		{
			if (!ft_isdigit(cmd->argv[1][i]))
			{
				printf("exit\nexit: %s: numeric argument required\n",
					cmd->argv[1]);
				state->exec_ret = 255;
				return (exit_with_error_code(state, 255));
			}
			i++;
		}
		state->exec_ret = ft_atoi(cmd->argv[1]);
		return (exit_with_error_code(state, ft_atoi(cmd->argv[1])));
	}
	state->exec_ret = 0;
	return (exit_without_error_check_leaks(state));
}
