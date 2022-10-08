/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manugarc <manugarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 15:34:54 by manu              #+#    #+#             */
/*   Updated: 2022/10/08 12:41:20 by manugarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>

#include "libft.h"
#include "minishell.h"
#include "array.h"

static char	*path_line(char **envp)
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

char	*path_to_absolute(char *cmd_str, t_mini *state)
{
	/* TODO: To be implemented! Check if cmd starts with / or not (absolute vs local path). */
	/* 'ls' => should return => '/bin/ls' */
	/* a cmd can also start (and use more) ... This is a relative path, it needs to get converted to absolute */
	/* if in path /users/user1/home, running '../program' should return '/users/user1/program' */
	/* free up original cmd if replaced, and return de malloc-ed one? */
	/* the funciton should not validate valid path/program, only convert'*/
	if (*cmd_str == '/')
		return (cmd_str);
	return (get_path(cmd_str, state->envp));
}
