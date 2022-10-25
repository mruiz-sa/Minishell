/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_cd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manu <manu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 21:16:07 by manu              #+#    #+#             */
/*   Updated: 2022/10/25 20:00:40 by manu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include "command.h"
#include "env.h"
#include "minishell.h"
#include "path.h"
#include "str.h"

static char	*get_new_pwd(t_simple_cmd	*cmd, t_mini *state)
{
	char	*new_pwd;

	new_pwd = NULL;
	if (cmd->argc < 2 || !ft_strncmp(cmd->argv[1], "~", 1))
		new_pwd = get_env_dup(state->envp, "HOME");
	else if (!ft_strncmp(cmd->argv[1], "-", 1))
		new_pwd = get_env_dup(state->envp, "OLDPWD");
	else
		new_pwd = ft_strdup(cmd->argv[1]);
	return (new_pwd);
}

int	run_builtin_cd(t_simple_cmd	*cmd, t_mini *state)
{
	char	*pwd;
	char	*old_pwd;
	char	*new_pwd;
	int		result;

	result = 0;
	new_pwd = get_new_pwd(cmd, state);
	if (new_pwd)
	{
		old_pwd = getcwd(NULL, 0);
		result = chdir(new_pwd);
		if (!result)
		{
			result = 1;
			pwd = getcwd(NULL, 0);
			state->envp = set_env(state->envp, "PWD", pwd);
			state->envp = set_env(state->envp, "OLDPWD", old_pwd);
			free(pwd);
		}
		free(new_pwd);
		free(old_pwd);
	}
	return (result);
}
