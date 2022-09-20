/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_command_table.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manu <manu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 18:57:48 by manu              #+#    #+#             */
/*   Updated: 2022/09/20 19:17:14 by manu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <assert.h>

#include "minishell.h"
#include "token.h"
#include "command_table.h"

void	test_command_tables(void)
{
	t_cmd	*table;

	table = tokens_to_cmd_table(str_to_tokens("ls"));
	assert(table != NULL);
	assert(table->ncmds == 1);
	assert(ft_lstsize(table->cmds) == 1);
	display_cmd_table(table);
}
