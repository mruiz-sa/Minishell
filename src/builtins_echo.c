/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_echo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manu <manu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 21:16:07 by manu              #+#    #+#             */
/*   Updated: 2022/10/31 18:03:37 by manu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command.h"
#include "error.h"
#include "minishell.h"

static void	print_escaped_str(char *str)
{
	char	prev;
	int		escape;

	prev = 0;
	escape = 1;
	while (str && *str)
	{
		if (*str == '\\' && escape)
			escape = 0;
		else
		{
			if (*str == '\\')
				escape = 1;
			printf("%c", *str);
		}
		prev = *str;
		str++;
	}
}

int	run_builtin_echo(t_simple_cmd	*cmd, t_mini *state)
{
	int	i;
	int	n;

	(void)state;
	i = 1;
	n = 0;
	if (cmd && cmd->argc > 1)
	{
		while (!ft_strncmp(cmd->argv[i], "-n", 2) && cmd->argv[i])
		{
			n = 1;
			i++;
		}
		while (i < cmd->argc)
		{
			print_escaped_str(cmd->argv[i++]);
			if (i < cmd->argc)
				printf(" ");
		}
	}
	if (n == 0)
		printf("\n");
	return (OK);
}
