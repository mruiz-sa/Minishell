/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manu <manu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 21:16:07 by manu              #+#    #+#             */
/*   Updated: 2022/10/17 23:00:25 by manu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins_cd.h"
#include "builtins_echo.h"
#include "builtins_env.h"
#include "builtins_export.h"
#include "builtins_pwd.h"
#include "builtins_unset.h"
#include "command.h"
#include "minishell.h"

t_builtin_type	get_builtin_type(char *str)
{
	if (ft_strnstr(str, "echo", ft_strlen("echo")))
		return (BLT_ECHO);
	else if (ft_strnstr(str, "cd", ft_strlen("cd")))
		return (BLT_CD);
	else if (ft_strnstr(str, "pwd", ft_strlen("pwd")))
		return (BLT_PWD);
	else if (ft_strnstr(str, "export", ft_strlen("export")))
		return (BLT_EXPORT);
	else if (ft_strnstr(str, "unset", ft_strlen("unset")))
		return (BLT_UNSET);
	else if (ft_strnstr(str, "env", ft_strlen("env")))
		return (BLT_ENV);
	else if (ft_strnstr(str, "exit", ft_strlen("exit")))
		return (BLT_EXIT);
	return (BLT_NONE);
}

int	is_parent_builtin(t_builtin_type type)
{
	if (type == BLT_NONE)
		return (0);
	return (1);
	if (type == BLT_ECHO || type == BLT_EXIT || type == BLT_ENV)
		return (0);
	return (1);
}

int	run_builtin(t_list *cmds)
{
	t_simple_cmd	*cmd;

	cmd = get_cmd(cmds);
	if (cmd->builtin_type == BLT_CD)
		return (run_builtin_cd(cmd));
	else if (cmd->builtin_type == BLT_ECHO)
		return (run_builtin_echo(cmd));
	else if (cmd->builtin_type == BLT_ENV)
		return (run_builtin_env(cmd));
	else if (cmd->builtin_type == BLT_EXPORT)
		return (run_builtin_export(cmd));
	else if (cmd->builtin_type == BLT_PWD)
		return (run_builtin_pwd(cmd));
	else if (cmd->builtin_type == BLT_UNSET)
		return (run_builtin_unset(cmd));
	return (0);
}
