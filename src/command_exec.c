/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_exec.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manu <manu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 11:52:38 by mruiz-sa          #+#    #+#             */
/*   Updated: 2022/10/18 21:03:18 by manu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"
#include "command.h"
#include "error.h"
#include "libft.h"
#include "minishell.h"
#include "redirection.h"

#define FD_IN 0
#define FD_OUT 1

static void	child_start(t_list *cmds, t_mini *state)
{
	t_simple_cmd	*cmd;

	cmd = get_cmd(cmds);
	apply_redirections(cmd->redirections);
	if (is_builtin(cmd))
	{
		run_builtin(cmds, state);
		exit_without_error(state);
	}
	else if (execve(cmd->argv[0], cmd->argv, state->envp) == -1)
	{
		ft_putendl_fd("command not found: ", 2);
		ft_putendl_fd(cmd->argv[0], 2);
		exit_with_error(state, "");
	}
}

void	exec_cmd(t_list *cmds, t_mini *state)
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
	if (is_parent_builtin(cmd->builtin_type))
		run_builtin(cmds, state);
	else
	{ 
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
			child_start(cmds, state);
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
}
