/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_exec.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manugarc <manugarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 11:52:38 by mruiz-sa          #+#    #+#             */
/*   Updated: 2022/11/10 20:05:31 by manugarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

	set_sigquit_signal();
	cmd = get_cmd(cmds);
	apply_redirections(cmd->redirections, state);
	if (!cmd->argv)
		exit_without_error(state);
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
		ft_putendl_fd(": No such file or directory", 2);
		exit_with_error_code(state, 127);
	}
}

static void	child_pipe(t_list *cmds, t_mini *state)
{
	t_simple_cmd	*cmd;

	cmd = get_cmd(cmds);
	if (get_cmd(cmds->next))
		close(cmd->pipe_fds[FD_IN]);
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

static void	parent_pipe(t_list *cmds)
{
	t_simple_cmd	*cmd;
	t_simple_cmd	*next_cmd;

	cmd = get_cmd(cmds);
	next_cmd = get_cmd(cmds->next);
	if (next_cmd)
	{
		next_cmd->fd_in = cmd->pipe_fds[FD_IN];
		close(cmd->pipe_fds[FD_OUT]);
	}
}

static int	ft_fork(void)
{
	int	pid;

	pid = fork();
	if (pid < 0)
		perror("Error");
	return (pid);
}

void	create_pipe(t_list *cmds, t_mini *state)
{
	t_simple_cmd	*cmd;

	cmd = get_cmd(cmds);
	if (get_cmd(cmds->next))
	{
		if (pipe(cmd->pipe_fds) == -1)
			exit_with_error(state, "Error calling pipe()");
		cmd->fd_out = cmd->pipe_fds[FD_OUT];
	}
}

void	wait_for_child(pid_t pid, t_mini *state)
{
	int				status;

	(void)state;
	signal(SIGINT, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
	set_sigquit_signal();
	waitpid(pid, &status, 0);
	if (WIFSIGNALED(status))
		g_exec_ret = 128 + WTERMSIG(status);
	else
		g_exec_ret = WEXITSTATUS(status);
	set_parent_signals();
}

void	exec_cmd(t_list *cmds, t_mini *state)
{
	t_simple_cmd	*cmd;

	cmd = get_cmd(cmds);
	create_pipe(cmds, state);
	if (is_parent_builtin(cmd->builtin_type))
	{
		parent_pipe(cmds);
		g_exec_ret = run_builtin(cmds, state);
	}
	else
	{
		cmd->pid = ft_fork();
		if (cmd->pid == 0)
			child_pipe(cmds, state);
		else
		{
			parent_pipe(cmds);
			wait_for_child(cmd->pid, state);
		}
	}
}
