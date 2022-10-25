/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_exit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruiz-sa <mruiz-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 21:16:07 by manu              #+#    #+#             */
/*   Updated: 2022/10/25 17:10:47 by mruiz-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command.h"
#include "error.h"
#include "minishell.h"

void	run_builtin_exit(t_simple_cmd	*cmd, t_mini *state)
{
	int	i;

	i = 0;
	(void)state;
	if (cmd->argc > 2)
		printf("exit: too many arguments\n");
	else if (cmd->argc == 2)
	{
		while (cmd->argv[1][i])
		{
			if (!ft_isdigit(cmd->argv[1][i]))
			{
				printf("exit: %s: numeric argument required\n", cmd->argv[1]);
				exit(255);
			}
			i++;
		}
		exit (ft_atoi(cmd->argv[1]));
	}
	else
		exit(0);
}
