/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manugarc <manugarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 11:52:38 by mruiz-sa          #+#    #+#             */
/*   Updated: 2022/10/03 20:48:19 by manugarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minishell.h"
#include "error.h"

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

void	exec_cmd(char *cmd, t_mini *state)
{
	char	**cmd_splitted;
	char	*path;

	cmd_splitted = ft_split(cmd, ' ');
	path = get_path(cmd_splitted[0], state->envp);
	if (execve(path, cmd_splitted, state->envp) == -1)
	{
		ft_putendl_fd("command not found: ", 2);
		ft_putendl_fd(cmd_splitted[0], 2);
		free_array(cmd_splitted);
		if (path)
			free(path);
		exit_with_error("");
	}
}
