/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_prompt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruiz-sa <mruiz-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 12:10:38 by mruiz-sa          #+#    #+#             */
/*   Updated: 2022/09/02 14:14:23 by mruiz-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft.h"

char	*get_pwd(char **envp)
{
	int		i;
	char	*pwd;

	i = 0;
	while (envp[i])
	{
		if (!ft_strncmp(envp[i], "PWD=", 4))
			pwd = envp[i];
		i++;
	}
	pwd = ft_strjoin(ft_strrchr(pwd, '/'), " % ");
	return (pwd);
}

char	*get_prompt(char **envp)
{
	int		i;
	char	*user;
	char	*prompt;

	i = 0;
	while (envp[i])
	{
		if (!ft_strncmp(envp[i], "USER=", 5))
			user = envp[i];
		i++;
	}
	i = 0;
	while (user[i])
	{
		if (user[i] == '=')
		{
			user = ft_strjoin(ft_strchr(user, user[i + 1]), " > ");
			break ;
		}
		i++;
	}
	prompt = ft_strjoin(ft_strjoin(ft_strjoin("\033[0;35m",
					ft_strjoin("minishell‣", user)), get_pwd(envp)), "\033[0m");
	return (prompt);
}
