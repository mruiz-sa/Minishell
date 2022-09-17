/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manugarc <manugarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 21:03:58 by manu              #+#    #+#             */
/*   Updated: 2022/09/17 10:53:32 by manugarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft.h"
#include "malloc.h"
#include "token.h"
#include "array.h"

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

t_list	*add_cmd(t_list *tokens, t_cmd *table)
{
	t_token			*token;
	t_simple_cmd	*cmd;
	int				cmd_found;

	cmd_found = 0;
	cmd = ft_malloc(sizeof(t_simple_cmd));
	if (!table->cmds)
		table->cmds = ft_lstnew(cmd);
	else
		ft_lstadd_back(&table->cmds, ft_lstnew(cmd));
	table->ncmds++;
	while (tokens)
	{
		token = get_token(tokens);
		if (token->type != TK_ARG && (token->type != TK_CMD || cmd_found))
			break ;
		if (token->type == TK_CMD)
			cmd_found = 1;
		cmd->argc++;
		cmd->argv = add_str_to_array(cmd->argv, token->str);
		tokens = tokens->next;
	}
	return (tokens);
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

t_simple_cmd	*get_cmd(t_list *cmd_node)
{
	if (cmd_node && cmd_node->content)
		return ((t_simple_cmd *)cmd_node->content);
	return (NULL);
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
