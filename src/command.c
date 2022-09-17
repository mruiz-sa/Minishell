/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manugarc <manugarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 21:03:58 by manu              #+#    #+#             */
/*   Updated: 2022/09/17 13:22:53 by manugarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "malloc.h"
#include "token.h"
#include "array.h"

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

t_simple_cmd	*get_cmd(t_list *cmd_node)
{
	if (cmd_node && cmd_node->content)
		return ((t_simple_cmd *)cmd_node->content);
	return (NULL);
}
