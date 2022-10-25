/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_exit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruiz-sa <mruiz-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 21:16:07 by manu              #+#    #+#             */
/*   Updated: 2022/10/25 17:24:21 by mruiz-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command.h"
#include "error.h"
#include "minishell.h"

void	run_builtin_exit(t_simple_cmd	*cmd)
{
	int	i;

	i = 0;
	if (cmd->argc > 2)
		printf("exit: too many arguments\n");
	else if (cmd->argc == 2)
	{
		while (cmd->argv[1][i])
		{
			if (!ft_isdigit(cmd->argv[1][i]))
			{
				printf("exit\nexit: %s: numeric argument required\n",
					cmd->argv[1]);
				exit(255);
			}
			i++;
		}
		printf("exit\n");
		exit (ft_atoi(cmd->argv[1]));
	}
	else
	{
		printf("exit\n");
		exit(0);
	}
}
