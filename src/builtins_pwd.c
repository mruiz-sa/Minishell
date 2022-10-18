/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_pwd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manu <manu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 21:16:07 by manu              #+#    #+#             */
/*   Updated: 2022/10/18 21:02:56 by manu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command.h"
#include "env.h"
#include "minishell.h"

int	run_builtin_pwd(t_simple_cmd	*cmd, t_mini *state)
{
	char	**envp;
	char	*pwd;

	(void)cmd;
	envp = state->envp;
	pwd = get_env(envp, "PWD");
	if (pwd)
		printf("%s\n", pwd);
	return (1);
}
