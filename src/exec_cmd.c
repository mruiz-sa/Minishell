/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manugarc <manugarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 11:52:38 by mruiz-sa          #+#    #+#             */
/*   Updated: 2022/10/08 10:14:55 by manugarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minishell.h"
#include "error.h"
#include "command.h"

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

char	*path_line(char **envp)
{
	int	i;

	i = 0;
	while (envp[i])
	{
		if (!ft_strncmp(envp[i], "PATH=", 5))
			return (envp[i]);
		i++;
	}
	return (NULL);
}

char	*get_path(char *cmd, char **envp)
{
	int		i;
	int		fd;
	char	**path_list;
	char	*path_slash;
	char	*path_arg;

	i = 0;
	path_list = ft_split(ft_strchr(path_line(envp), '/'), ':');
	while (path_list[i])
	{
		path_slash = ft_strjoin(path_list[i], "/");
		path_arg = ft_strjoin(path_slash, cmd);
		free(path_slash);
		fd = open(path_arg, O_RDONLY);
		if (fd >= 0)
		{
			free_array(path_list);
			close(fd);
			return (path_arg);
		}
		free(path_arg);
		i++;
	}
	free_array(path_list);
	return (NULL);
}

void	exec_cmd_table(t_cmd *table, t_mini *state)
{
	t_list			*cmds;
	t_simple_cmd	*cmd;
	pid_t			pid;
	char			*path;

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
			path = get_path(cmd->argv[0], state->envp);
			if (execve(path, cmd->argv, state->envp) == -1)
			{
				ft_putendl_fd("command not found: ", 2);
				ft_putendl_fd(cmd->argv[0], 2);
				if (path)
					free(path);
				exit_with_error(state, "");
			}
		}
		else
			waitpid(pid, NULL, 0);
		cmds = cmds->next;
	}
}
