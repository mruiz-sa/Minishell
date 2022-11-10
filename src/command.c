/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manugarc <manugarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 21:03:58 by manu              #+#    #+#             */
/*   Updated: 2022/11/10 20:27:00 by manugarc         ###   ########.fr       */
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
