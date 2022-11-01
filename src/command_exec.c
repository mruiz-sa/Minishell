/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_exec.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manu <manu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 11:52:38 by mruiz-sa          #+#    #+#             */
/*   Updated: 2022/11/01 18:37:24 by manu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <sys/wait.h>

#include "builtins.h"
#include "command.h"
#include "error.h"
#include "libft.h"
#include "minishell.h"
#include "redirection.h"
#include "signals.h"

#define FD_IN 0
#define FD_OUT 1

static void	child_start(t_list *cmds, t_mini *state)
{
	t_simple_cmd	*cmd;
	int				result;

	set_child_signals();
	cmd = get_cmd(cmds);
	apply_redirections(cmd->redirections, state);
	if (is_builtin(cmd))
	{
		result = run_builtin(cmds, state);
		if (result == OK)
			exit_without_error(state);
		else
			exit_with_error_code(state, result);
	}
	else if (execve(cmd->argv[0], cmd->argv, state->envp) == -1)
	{
		ft_putstr_fd(cmd->argv[0], 2);
		ft_putendl_fd(": command not found", 2);
		// printf("Errno is %d\n", errno);
		exit_with_error_code(state, errno);
	}
}

void	exec_cmd(t_list *cmds, t_mini *state)
{
	pid_t			pid;
	int				fd[2];
	t_simple_cmd	*cmd;
	t_simple_cmd	*next_cmd;
	int				status;

	cmd = get_cmd(cmds);
	next_cmd = get_cmd(cmds->next);
	if (next_cmd)
	{
		if (pipe(fd) == -1)
			exit_with_error(state, "Error calling pipe()");
		cmd->fd_out = fd[FD_OUT];
	}
	if (is_parent_builtin(cmd->builtin_type))
		state->exec_ret = run_builtin(cmds, state);
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
			unset_signals();
			waitpid(pid, &status, 0);
			state->exec_ret = WEXITSTATUS(status);
			if (WIFSIGNALED(status))
			{
				if (WTERMSIG(status))
					state->exec_ret = 128 + WTERMSIG(status);
			}
			set_parent_signals();
			// printf("wait status is %d\n", status);
			// printf("wait WEXITSTATUS is %d\n", WEXITSTATUS(status));
			// printf("wait WIFEXITED is %d\n", WIFEXITED(status));
			// printf("wait WIFSIGNALED is %d\n", WIFSIGNALED(status));
		}
	}
}
