/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manu <manu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 21:03:21 by manu              #+#    #+#             */
/*   Updated: 2022/11/06 12:15:57 by manu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMAND_H
# define COMMAND_H

# include "minishell.h"

t_list			*add_cmd(t_list *tokens, t_cmd *table);
t_simple_cmd	*get_cmd(t_list *cmd_node);
int				is_builtin(t_simple_cmd *cmd);
int				is_cmd_arg_quoted(t_simple_cmd *cmd, int argc);

#endif
