/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_table.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manu <manu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 21:03:58 by manu              #+#    #+#             */
/*   Updated: 2022/10/31 16:44:23 by manu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command.h"
#include "command_exec.h"
#include "malloc.h"
#include "minishell.h"
#include "redirection.h"
#include "token.h"
#include "token_type.h"

static void	free_node_content(void *content)
{
	t_simple_cmd	*cmd;

	cmd = content;
	if (!cmd)
		return ;
	if (cmd->argv != NULL)
		free_array(cmd->argv);
	if (cmd->redirections != NULL)
		free_redirections(cmd->redirections);
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
		if (!token->ignore
			&& (token->type == TK_CMD || is_token_redirection(token->type)))
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
		printf("\nPrinting command (%s) and argv\n", cmd->argv[0]);
		i = 0;
		while (cmd->argv && cmd->argv[i])
		{
			printf("Command argv[%d] = %s\n", i, cmd->argv[i]);
			i++;
		}
		if (cmd->redirections)
		{
			printf("Command has redirections:\n");
			display_redirections(cmd->redirections);
		}
		printf("\n");
		cmds = cmds->next;
	}
}

void	exec_cmd_table(t_cmd *table, t_mini *state)
{
	t_list			*cmds;

	if (!table)
		return ;
	cmds = table->cmds;
	while (cmds)
	{
		exec_cmd(cmds, state);
		cmds = cmds->next;
	}
}
