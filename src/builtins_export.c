/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_export.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruiz-sa <mruiz-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 21:16:07 by manu              #+#    #+#             */
/*   Updated: 2022/11/02 17:28:21 by mruiz-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "array.h"
#include "command.h"
#include "env.h"
#include "error.h"
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
	return (OK);
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

static int	variable_checker(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isalnum(str[i]))
			return (0);
		i++;
	}
	return (1);
}

static int	export_variable_blocks(t_simple_cmd	*cmd, t_mini *state)
{
	char	**keys;
	int		i;

	i = 1;
	while (i < cmd->argc)
	{	
		if (!variable_checker(cmd->argv[i]))
		{
			ft_putstr_fd("export: '", 2);
			ft_putstr_fd(cmd->argv[i], 2);
			ft_putendl_fd("': not a valid identifier", 2);
			return (ERROR);
		}
		keys = ft_split(cmd->argv[i], ' ');
		state->envp = export_variables(keys, state->envp);
		free_array(keys);
		i++;
	}
	return (OK);
}

int	run_builtin_export(t_simple_cmd	*cmd, t_mini *state)
{
	if (cmd->argc < 2)
		return (display_export(state));
	return (export_variable_blocks(cmd, state));
}
