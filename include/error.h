/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manu <manu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 18:54:34 by manu              #+#    #+#             */
/*   Updated: 2022/10/25 21:31:06 by manu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

# include "minishell.h"

# define ERROR_NONE			0
# define ERROR_GENERIC		1

int	exit_with_error(t_mini *state, char *message_error);
int	exit_with_memory_error(t_mini *state);
int	exit_without_error(t_mini *state);
int	exit_without_error_check_leaks(t_mini *state);
int	exit_with_error_code(t_mini *state, int exit_code);

#endif
