/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_table.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manu <manu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 13:17:43 by manugarc          #+#    #+#             */
/*   Updated: 2022/10/16 12:27:54 by manu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMAND_TABLE_H
# define COMMAND_TABLE_H

# include "minishell.h"

void	free_cmd_table(t_cmd *table);
t_cmd	*tokens_to_cmd_table(t_list *tokens);
void	display_cmd_table(t_cmd *table);
void	exec_cmd_table(t_cmd *table, t_mini *state);

#endif
