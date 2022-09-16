/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manu <manu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 21:03:21 by manu              #+#    #+#             */
/*   Updated: 2022/09/16 21:03:23 by manu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMAND_H
# define COMMAND_H

# include "minishell.h"

void	free_cmd_table(t_cmd *table);
t_cmd	*tokens_to_cmd_table(t_list *tokens);
void	display_cmd_table(t_cmd *table);

#endif
