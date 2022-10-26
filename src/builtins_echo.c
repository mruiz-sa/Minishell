/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_echo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruiz-sa <mruiz-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 21:16:07 by manu              #+#    #+#             */
/*   Updated: 2022/10/26 19:26:28 by mruiz-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command.h"
#include "minishell.h"

int	run_builtin_echo(t_simple_cmd	*cmd, t_mini *state)
{
	int	i;
	int	n;

	i = 1;
	n = 0;
	if (cmd && cmd->argc > 1)
	{
		while (!ft_strncmp(cmd->argv[i], "-n", 2) && cmd->argv[i])
		{
			n = 1;
			i++;
		}
		while (i < cmd->argc)
		{
			printf("%s", cmd->argv[i++]);
			if (i < cmd->argc)
				printf(" ");
		}
	}
	if (n == 0)
		printf("\n");
	state->exec_ret = 0;
	return (1);
}
