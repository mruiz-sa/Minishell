/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_env.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruiz-sa <mruiz-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 21:16:07 by manu              #+#    #+#             */
/*   Updated: 2022/10/26 19:26:34 by mruiz-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "array.h"
#include "command.h"
#include "minishell.h"

int	run_builtin_env(t_simple_cmd	*cmd, t_mini *state)
{
	char	**envp;
	char	**expanded;
	int		i;

	(void)cmd;
	envp = state->envp;
	i = 0;
	while (envp[i])
	{
		expanded = ft_split(envp[i], '=');
		if (expanded)
		{
			if (ft_strlen(expanded[1]))
				printf("%s\n", envp[i]);
			free_array(expanded);
		}
		i++;
	}
	state->exec_ret = 0;
	return (1);
}
