/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_export.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruiz-sa <mruiz-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 21:16:07 by manu              #+#    #+#             */
/*   Updated: 2022/11/09 18:17:30 by mruiz-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "array.h"
#include "command.h"
#include "env.h"
#include "error.h"
#include "minishell.h"

static int	syntax_error(char *str)
{
	ft_putstr_fd("export: '", 2);
	ft_putstr_fd(str, 2);
	ft_putendl_fd("': not a valid identifier", 2);
	return (0);
}

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

static int	variable_checker(char *str)
{
	int	i;

	i = 0;
	if (!ft_isalpha(str[i]))
		return (0);
	while (str[i])
	{
		if (!ft_isalnum(str[i]) && str[i] != '=')
			return (0);
		i++;
	}
	return (1);
}

static int	is_valid_export(char *variables)
{
	char	**variable_split;
	int		result;

	result = 1;
	if (result == 1 && ft_strlen(variables))
	{
		if (variables[0] == '=' && variables[1] == '\0')
		{
			syntax_error(variables);
			result = 0;
		}
		else
		{
			variable_split = ft_split(variables, '=');
			if (!variable_checker(variable_split[0]))
			{
				syntax_error(variable_split[0]);
				result = 0;
			}
			free_array(variable_split);
		}
	}
	return (result);
}

static char	**export_variables(char *variables, char **envp)
{
	char	**variable_split;
	int		i;

	i = 0;
	if (ft_strlen(variables))
	{
		variable_split = ft_split(variables, '=');
		envp = del_str_from_array(envp, variable_split[0]);
		envp = add_str_to_array(envp, variables);
		free_array(variable_split);
		i++;
	}
	return (envp);
}

static int	export_variable_blocks(t_simple_cmd	*cmd, t_mini *state)
{
	int		i;
	int		result;

	result = OK;
	i = 1;
	while (i < cmd->argc)
	{	
		if (!is_valid_export(cmd->argv[i]))
			result = ERROR;
		else
			state->envp = export_variables(cmd->argv[i], state->envp);
		i++;
	}
	return (result);
}

int	run_builtin_export(t_simple_cmd	*cmd, t_mini *state)
{
	if (cmd->argc < 2)
		return (display_export(state));
	return (export_variable_blocks(cmd, state));
}
