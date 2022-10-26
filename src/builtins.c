/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruiz-sa <mruiz-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 21:16:07 by manu              #+#    #+#             */
/*   Updated: 2022/10/26 18:42:33 by mruiz-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins_cd.h"
#include "builtins_echo.h"
#include "builtins_env.h"
#include "builtins_exit.h"
#include "builtins_export.h"
#include "builtins_pwd.h"
#include "builtins_unset.h"
#include "command.h"
#include "minishell.h"
#include "path.h"

t_builtin_type	get_builtin_type(char *str)
{
	char			*builtin;
	t_builtin_type	type;

	type = BLT_NONE;
	builtin = get_last_part_in_path(str);
	if (ft_strnstr(builtin, "echo", ft_strlen("echo")))
		type = BLT_ECHO;
	else if (ft_strnstr(builtin, "cd", ft_strlen("cd")))
		type = BLT_CD;
	else if (ft_strnstr(builtin, "pwd", ft_strlen("pwd")))
		type = BLT_PWD;
	else if (ft_strnstr(builtin, "export", ft_strlen("export")))
		type = BLT_EXPORT;
	else if (ft_strnstr(builtin, "unset", ft_strlen("unset")))
		type = BLT_UNSET;
	else if (ft_strnstr(builtin, "env", ft_strlen("env")))
		type = BLT_ENV;
	else if (ft_strnstr(builtin, "exit", ft_strlen("exit")))
		type = BLT_EXIT;
	free(builtin);
	return (type);
}

int	is_parent_builtin(t_builtin_type type)
{
	if (type == BLT_NONE || type == BLT_ECHO || type == BLT_ENV
		|| type == BLT_PWD)
		return (0);
	return (1);
}

int	run_builtin(t_list *cmds, t_mini *state)
{
	t_simple_cmd	*cmd;

	cmd = get_cmd(cmds);
	if (cmd->builtin_type == BLT_CD)
		return (run_builtin_cd(cmd, state));
	else if (cmd->builtin_type == BLT_ECHO)
		return (run_builtin_echo(cmd, state));
	else if (cmd->builtin_type == BLT_ENV)
		return (run_builtin_env(cmd, state));
	else if (cmd->builtin_type == BLT_EXPORT)
		return (run_builtin_export(cmd, state));
	else if (cmd->builtin_type == BLT_PWD)
		return (run_builtin_pwd(cmd, state));
	else if (cmd->builtin_type == BLT_UNSET)
		return (run_builtin_unset(cmd, state));
	else if (cmd->builtin_type == BLT_EXIT)
		return (run_builtin_exit(cmd, state));
	return (0);
}
