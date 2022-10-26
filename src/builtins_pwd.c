/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_pwd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruiz-sa <mruiz-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 21:16:07 by manu              #+#    #+#             */
/*   Updated: 2022/10/26 19:27:03 by mruiz-sa         ###   ########.fr       */
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
	state->exec_ret = 0;
	return (1);
}
