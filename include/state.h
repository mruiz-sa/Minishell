/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manu <manu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 16:07:36 by manu              #+#    #+#             */
/*   Updated: 2022/09/05 17:03:49 by manu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STATE_H
# define STATE_H

# include "minishell.h"

t_mini		g_state;

int	init_state(t_mini *state, int argc, char *argv[], char **envp);
int	free_state(t_mini *state);

#endif