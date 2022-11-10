/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_exec_child.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manugarc <manugarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 11:52:38 by mruiz-sa          #+#    #+#             */
/*   Updated: 2022/11/10 20:22:32 by manugarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/wait.h>

#include "builtins.h"
#include "command.h"
#include "error.h"
#include "libft.h"
#include "minishell.h"
#include "redirection_apply.h"
#include "signals.h"

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

void	child_pipe(t_list *cmds, t_mini *state)
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
