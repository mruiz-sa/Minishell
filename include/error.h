/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manu <manu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 18:54:34 by manu              #+#    #+#             */
/*   Updated: 2022/09/09 18:54:36 by manu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

# define ERROR_NONE			0
# define ERROR_GENERIC		1

int	exit_with_error(char *message_error);
int	exit_with_memory_error(void);
int	exit_without_error(void);

#endif
