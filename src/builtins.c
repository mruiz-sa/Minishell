/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manu <manu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 21:16:07 by manu              #+#    #+#             */
/*   Updated: 2022/10/31 19:47:57 by manu             ###   ########.fr       */
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
#include "error.h"
#include "libft.h"
#include "minishell.h"
#include "path.h"
#include "str.h"

static int	is_builtin_str(char *builtin, char *str)
{
	if (!ft_strncmp(builtin, str, ft_strlen(str) + 1))
		return (1);
	return (0);
}

t_builtin_type	get_builtin_type(char *str)
{
	char			*builtin;
	t_builtin_type	type;

	type = BLT_NONE;
	builtin = ft_str_tolower(get_last_part_in_path(str));
	if (is_builtin_str(builtin, "echo"))
		type = BLT_ECHO;
	else if (is_builtin_str(builtin, "cd"))
		type = BLT_CD;
	else if (is_builtin_str(builtin, "pwd"))
		type = BLT_PWD;
	else if (is_builtin_str(builtin, "export"))
		type = BLT_EXPORT;
	else if (is_builtin_str(builtin, "unset"))
		type = BLT_UNSET;
	else if (is_builtin_str(builtin, "env"))
		type = BLT_ENV;
	else if (is_builtin_str(builtin, "exit"))
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
	return (ERROR);
}
