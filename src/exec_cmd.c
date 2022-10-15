/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manu <manu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 11:52:38 by mruiz-sa          #+#    #+#             */
/*   Updated: 2022/10/15 22:07:36 by manu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command.h"
#include "error.h"
#include "libft.h"
#include "minishell.h"
#include "redirection.h"

#define FD_IN 0
#define FD_OUT 1

static void	child_start(t_simple_cmd *cmd, t_mini *state)
{
	apply_redirections(cmd->redirections);
	if (execve(cmd->argv[0], cmd->argv, state->envp) == -1)
	{
		ft_putendl_fd("command not found: ", 2);
		ft_putendl_fd(cmd->argv[0], 2);
		exit_with_error(state, "");
	}
}

static void	exec_cmd(t_list *cmds, t_mini *state)
{
	pid_t			pid;
	int				fd[2];
	t_simple_cmd	*cmd;
	t_simple_cmd	*next_cmd;

	cmd = get_cmd(cmds);
	next_cmd = get_cmd(cmds->next);
	if (next_cmd)
	{
		if (pipe(fd) == -1)
			exit_with_error(state, "Error calling pipe()");
		cmd->fd_out = fd[FD_OUT];
	}
	pid = fork();
	if (pid < 0)
		perror("Error");
	if (pid == 0)
	{
		if (next_cmd)
			close(fd[FD_IN]);
		if (cmd->fd_in)
		{
			dup2(cmd->fd_in, STDIN_FILENO);
			close(cmd->fd_in);
		}
		if (cmd->fd_out)
		{
			dup2(cmd->fd_out, STDOUT_FILENO);
			close(cmd->fd_out);
		}
		child_start(cmd, state);
	}
	else
	{
		if (next_cmd)
		{
			next_cmd->fd_in = fd[FD_IN];
			close(fd[FD_OUT]);
		}
		waitpid(pid, NULL, 0);
	}
}

void	exec_cmd_table(t_cmd *table, t_mini *state)
{
	t_list			*cmds;
	t_simple_cmd	*cmd;

	if (!table)
		return ;
	cmds = table->cmds;
	cmd = get_cmd(cmds);
	// if (is_builtin(cmd))
	// {
	// 	Esto es un builtin. Algunos se ejecutan en proceso padre otros con fork!
	// }
	while (cmds)
	{
		exec_cmd(cmds, state);
		cmds = cmds->next;
	}
}
