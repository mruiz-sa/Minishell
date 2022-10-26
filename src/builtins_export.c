/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_export.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruiz-sa <mruiz-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 21:16:07 by manu              #+#    #+#             */
/*   Updated: 2022/10/26 19:26:58 by mruiz-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "array.h"
#include "command.h"
#include "env.h"
#include "minishell.h"

static int	display_export(t_mini *state)
{
	char	**envp;
	int		i;

	envp = state->envp;
	i = 0;
	while (envp[i])
	{
		printf("declare -x %s\n", envp[i++]);
	}
	return (1);
}

static char	**export_variables(char **variables, char **envp)
{
	char	**variable_split;
	int		i;

	i = 0;
	while (variables[i])
	{
		variable_split = ft_split(variables[i], '=');
		envp = del_str_from_array(envp, variable_split[0]);
		envp = add_str_to_array(envp, variables[i]);
		free_array(variable_split);
		i++;
	}
	return (envp);
}

static int	export_variable_blocks(t_simple_cmd	*cmd, t_mini *state)
{
	char	**keys;
	int		i;

	i = 1;
	while (i < cmd->argc)
	{
		keys = ft_split(cmd->argv[i], ' ');
		state->envp = export_variables(keys, state->envp);
		free_array(keys);
		i++;
	}
	return (1);
}

int	run_builtin_export(t_simple_cmd	*cmd, t_mini *state)
{
	if (cmd->argc < 2)
	{
		state->exec_ret = 0;
		return (display_export(state));
	}
	state->exec_ret = 0;
	return (export_variable_blocks(cmd, state));
}
