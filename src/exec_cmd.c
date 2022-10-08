/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manugarc <manugarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 11:52:38 by mruiz-sa          #+#    #+#             */
/*   Updated: 2022/10/08 12:08:49 by manugarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minishell.h"
#include "error.h"
#include "command.h"

void	exec_cmd_table(t_cmd *table, t_mini *state)
{
	t_list			*cmds;
	t_simple_cmd	*cmd;
	pid_t			pid;

	if (!table)
		return ;
	cmds = table->cmds;
	while (cmds)
	{
		cmd = get_cmd(cmds);
		if (is_builtin(cmd))
		{
			// Esto es un builtin. Algunos se ejecutan en proceso padre otros con fork!
		}
		pid = fork();
		if (pid == -1)
			perror("ERROR");
		if (pid == 0)
		{
			if (execve(cmd->argv[0], cmd->argv, state->envp) == -1)
			{
				ft_putendl_fd("command not found: ", 2);
				ft_putendl_fd(cmd->argv[0], 2);
				exit_with_error(state, "");
			}
		}
		else
			waitpid(pid, NULL, 0);
		cmds = cmds->next;
	}
}
