/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_add.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manugarc <manugarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 21:03:21 by manu              #+#    #+#             */
/*   Updated: 2022/11/10 20:27:52 by manugarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMAND_ADD_H
# define COMMAND_ADD_H

# include "minishell.h"

t_list			*add_cmd(t_list *tokens, t_cmd *table);

#endif
