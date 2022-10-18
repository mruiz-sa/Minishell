/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_echo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manu <manu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 21:16:07 by manu              #+#    #+#             */
/*   Updated: 2022/10/18 21:02:46 by manu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command.h"
#include "minishell.h"

int	run_builtin_echo(t_simple_cmd	*cmd, t_mini *state)
{
	int	i;

	(void)state;
	i = 1;
	if (cmd && cmd->argc > 1)
	{
		while (i < cmd->argc)
		{
			printf("%s", cmd->argv[i++]);
			if (i < cmd->argc)
				printf(" ");
		}
	}
	printf("\n");
	return (1);
}
