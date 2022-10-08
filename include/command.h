/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manugarc <manugarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 21:03:21 by manu              #+#    #+#             */
/*   Updated: 2022/10/08 10:13:22 by manugarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMAND_H
# define COMMAND_H

# include "minishell.h"

t_list			*add_cmd(t_list *tokens, t_cmd *table);
t_simple_cmd	*get_cmd(t_list *cmd_node);
int				is_builtin(t_simple_cmd *cmd);

#endif
