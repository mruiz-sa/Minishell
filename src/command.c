/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manu <manu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 21:03:58 by manu              #+#    #+#             */
/*   Updated: 2022/11/01 16:52:55 by manu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "array.h"
#include "builtins.h"
#include "error.h"
#include "libft.h"
#include "malloc.h"
#include "minishell.h"
#include "redirection.h"
#include "token.h"
#include "token_type.h"

static t_list	*add_redirection_to_cmd(t_list *tokens, t_simple_cmd *cmd)
{
	t_token			*token;
	t_redirection	*redirection;

	token = get_token(tokens);
	redirection = ft_malloc(sizeof(t_redirection));
	redirection->type = token->type;
	token = get_token(tokens->next);
	if (token && token->str)
		redirection->file = ft_strdup(token->str);
	ft_lstadd_back(&cmd->redirections, ft_lstnew(redirection));
	return (tokens->next);
}

t_list	*add_cmd(t_list *tokens, t_cmd *table)
{
	t_token			*token;
	t_simple_cmd	*cmd;
	int				cmd_found;

	cmd_found = 0;
	cmd = ft_malloc(sizeof(t_simple_cmd));
	ft_lstadd_back(&table->cmds, ft_lstnew(cmd));
	table->ncmds++;
	while (tokens)
	{
		token = get_token(tokens);
		if (is_token_redirection(token->type))
			tokens = add_redirection_to_cmd(tokens, cmd);
		else
		{
			if (token->type != TK_ARG && (token->type != TK_CMD || cmd_found))
				break ;
			if (token->type == TK_CMD)
			{
				cmd_found = 1;
				cmd->builtin_type = get_builtin_type(token->str);
			}
			cmd->argc++;
			cmd->argv = add_str_to_array(cmd->argv, token->str);
		}
		if (tokens)
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

int	is_builtin(t_simple_cmd *cmd)
{
	if (cmd->builtin_type != BLT_NONE)
		return (1);
	return (0);
}
