/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_unset.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manu <manu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 21:16:07 by manu              #+#    #+#             */
/*   Updated: 2022/10/24 19:15:35 by manu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "array.h"
#include "command.h"
#include "minishell.h"

static char	**remove_keys_from_array(char **array, char	**keys)
{
	int		i;

	i = 0;
	while (keys && keys[i])
	{
		array = del_str_from_array(array, keys[i]);
		i++;
	}
	return (array);
}

int	run_builtin_unset(t_simple_cmd	*cmd, t_mini *state)
{
	char	**keys;
	int		i;

	if (cmd->argc < 2)
		return (1);
	i = 1;
	while (i < cmd->argc)
	{
		keys = ft_split(cmd->argv[i], ' ');
		state->envp = remove_keys_from_array(state->envp, keys);
		free_array(keys);
		i++;
	}
	return (1);
}
