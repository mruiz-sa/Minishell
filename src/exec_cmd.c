/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruiz-sa <mruiz-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 11:52:38 by mruiz-sa          #+#    #+#             */
/*   Updated: 2022/10/08 14:48:07 by mruiz-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minishell.h"
#include "error.h"
#include "command.h"

static void	child_start(t_simple_cmd *cmd, t_mini *state)
{
	if (execve(cmd->argv[0], cmd->argv, state->envp) == -1)
	{
		ft_putendl_fd("command not found: ", 2);
		ft_putendl_fd(cmd->argv[0], 2);
		exit_with_error(state, "");
	}
}

static void	pipex(t_simple_cmd	*cmd, t_mini *state)
{
	pid_t	pid;
	int		fd[2];

	pipe(fd);
	pid = fork();
	if (pid < 0)
		perror("Error");
	if (pid == 0)
	{
		close(fd[0]);
		dup2(fd[1], STDOUT_FILENO);
		close(fd[1]);
		child_start(cmd, state);
	}
	else
	{
		close(fd[1]);
		wait(NULL);
		dup2(fd[0], STDIN_FILENO);
		close(fd[0]);
	}
}

static void	exec_one_cmd(t_simple_cmd	*cmd, t_mini *state)
{
	pid_t	pid;

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
}

static void	exec_multiple_cmds(t_simple_cmd	*cmd, t_list *cmds, t_mini *state)
{
	int	i;
	int	size;

	i = 0;
	size = ft_lstsize(cmds);
	while (i < size)
	{
		pipex(cmd, state);
		if (i < size - 1)
		{
			cmds = cmds->next;
			cmd = get_cmd(cmds);
		}
		i++;
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
	if (cmds->next)
		exec_multiple_cmds(cmd, cmds, state);
	else
		exec_one_cmd(cmd, state);
}
