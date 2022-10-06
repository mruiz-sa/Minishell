/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_prompt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruiz-sa <mruiz-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 12:10:38 by mruiz-sa          #+#    #+#             */
/*   Updated: 2022/10/06 19:59:36 by mruiz-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft.h"
#include "env.h"

#include<stdio.h>

void	get_pwd(char **envp, t_prompt *prompt)
{
	char	*pwd;

	pwd = get_env(envp, "PWD");
	if (!pwd)
		return ;
	pwd = ft_strrchr(pwd, '/');
	if (!pwd)
		return ;
	pwd++;
	if (prompt->pwd)
	{
		free(prompt->pwd);
		prompt->pwd = NULL;
	}
	prompt->pwd = ft_strjoin(pwd, " % ");
}

void	get_prompt(char **envp, t_prompt *prompt)
{
	char	*user;

	user = get_env(envp, "USER");
	if (!user)
		return ;
	user = ft_strjoin(user, " > ");
	if (!user)
		return ;
	get_pwd(envp, prompt);
	prompt->user = ft_strjoin("minishell ", user);
	free(user);
	prompt->prompt = ft_strjoin(prompt->user, prompt->pwd);
}
