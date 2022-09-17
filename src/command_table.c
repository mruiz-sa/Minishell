/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_table.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manugarc <manugarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 21:03:58 by manu              #+#    #+#             */
/*   Updated: 2022/09/17 13:21:57 by manugarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "malloc.h"
#include "token.h"
#include "command.h"

static void	free_node_content(void *content)
{
	t_simple_cmd	*cmd;

	cmd = content;
	if (!cmd)
		return ;
	if (cmd->argv != NULL)
		free_array(cmd->argv);
	free(cmd);
}

void	free_cmd_table(t_cmd *table)
{
	if (!table)
		return ;
	ft_lstclear(&table->cmds, free_node_content);
	free(table);
}

// echo hi | cd test | pwd >> outfile.txt > outfile2.txt < infile &
t_cmd	*tokens_to_cmd_table(t_list *tokens)
{
	t_cmd	*table;
	t_token	*token;

	table = ft_malloc(sizeof(t_cmd));
	while (tokens)
	{
		token = get_token(tokens);
		if (token->type == TK_CMD)
			tokens = add_cmd(tokens, table);
		else
			tokens = tokens->next;
	}
	return (table);
}

void	display_cmd_table(t_cmd *table)
{
	t_list			*cmds;
	t_simple_cmd	*cmd;
	int				i;

	if (!table)
		return ;
	cmds = table->cmds;
	while (cmds)
	{
		cmd = get_cmd(cmds);
		printf("Printing command (%s) and argv\n", cmd->argv[0]);
		i = 0;
		while (cmd->argv && cmd->argv[i])
		{
			printf("Command argv[%d] = %s\n", i, cmd->argv[i]);
			i++;
		}
		printf("\n");
		cmds = cmds->next;
	}
}
