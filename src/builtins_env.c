/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_env.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manu <manu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 21:16:07 by manu              #+#    #+#             */
/*   Updated: 2022/11/08 20:17:04 by manu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "array.h"
#include "command.h"
#include "error.h"
#include "minishell.h"

// int	run_builtin_env(t_simple_cmd	*cmd, t_mini *state)
// {
// 	char	**envp;
// 	char	**expanded;
// 	int		i;

// 	(void)cmd;
// 	envp = state->envp;
// 	i = 0;
// 	while (envp[i])
// 	{
// 		expanded = ft_split(envp[i], '=');
// 		if (expanded)
// 		{
// 			if (ft_strlen(expanded[1]))
// 				printf("%s\n", envp[i]);
// 			free_array(expanded);
// 		}
// 		i++;
// 	}
// 	return (OK);
// }

int	run_builtin_env(t_simple_cmd	*cmd, t_mini *state)
{
	char	**envp;
	int		i;
	int		j;

	(void)cmd;
	envp = state->envp;
	i = 0;
	while (envp && envp[i])
	{
		j = 0;
		while (envp[i][j])
		{
			if (envp[i][j] == '=')
			{
				printf("%s\n", envp[i]);
				break ;
			}
			j++;
		}
		i++;
	}
	return (OK);
}
