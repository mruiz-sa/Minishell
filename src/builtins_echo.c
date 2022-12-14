/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_echo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manu <manu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 21:16:07 by manu              #+#    #+#             */
/*   Updated: 2022/11/06 12:16:08 by manu             ###   ########.fr       */
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

static int	is_new_line_flag(char *str)
{
	int	is_new_line;

	if (!str || *str != '-')
		return (0);
	str++;
	is_new_line = 0;
	while (str && *str)
	{
		if (*str == ' ')
			return (0);
		if (*str != 'n')
			return (0);
		is_new_line = 1;
		str++;
	}
	return (is_new_line);
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
		while (is_new_line_flag(cmd->argv[i]))
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
