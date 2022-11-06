/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manu <manu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 21:03:58 by manu              #+#    #+#             */
/*   Updated: 2022/11/06 12:16:20 by manu             ###   ########.fr       */
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

static void	add_token_str_to_cmd(t_simple_cmd	*cmd, t_token *token)
{
	if (token->double_quote)
		cmd->argv_quoted = add_str_to_array(cmd->argv_quoted, "\"");
	else if (token->single_quote)
		cmd->argv_quoted = add_str_to_array(cmd->argv_quoted, "\'");
	else
		cmd->argv_quoted = add_str_to_array(cmd->argv_quoted, "");
	cmd->argc++;
	cmd->argv = add_str_to_array(cmd->argv, token->str);
}

int	is_cmd_arg_quoted(t_simple_cmd *cmd, int argc)
{
	if (!cmd || !cmd->argv || cmd->argc < argc)
		return (0);
	if (!ft_strlen(cmd->argv[argc]) || !ft_strlen(cmd->argv_quoted[argc]))
		return (0);
	if (ft_strncmp(cmd->argv_quoted[argc], "\"", 1)
		&& ft_strncmp(cmd->argv_quoted[argc], "\'", 1))
		return (0);
	return (1);
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
		if (!token->ignore && is_token_redirection(token->type))
			tokens = add_redirection_to_cmd(tokens, cmd);
		else if (!token->ignore)
		{
			if (token->type != TK_ARG && (token->type != TK_CMD || cmd_found))
				break ;
			if (token->type == TK_CMD)
			{
				cmd_found = 1;
				cmd->builtin_type = get_builtin_type(token->str);
			}
			add_token_str_to_cmd(cmd, token);
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
