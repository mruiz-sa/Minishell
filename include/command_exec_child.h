/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_exec_child.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manugarc <manugarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 21:03:21 by manu              #+#    #+#             */
/*   Updated: 2022/11/10 20:23:53 by manugarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMAND_EXEC_CHILD_H
# define COMMAND_EXEC_CHILD_H

# include "minishell.h"

void	child_pipe(t_list *cmds, t_mini *state);

#endif
