/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_export.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manugarc <manugarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 21:16:07 by manu              #+#    #+#             */
/*   Updated: 2022/11/10 20:35:14 by manugarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "array.h"
#include "builtins_export_is.h"
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
