/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manu <manu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 16:07:36 by manu              #+#    #+#             */
/*   Updated: 2022/09/24 14:55:05 by manu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STATE_H
# define STATE_H

# include "minishell.h"

int	init_state(t_mini *state, int argc, char *argv[], char **envp);
int	free_state(t_mini *state);

#endif