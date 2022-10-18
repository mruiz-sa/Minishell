/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manu <manu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 15:54:12 by manu              #+#    #+#             */
/*   Updated: 2022/10/18 21:02:38 by manu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PATH_H
# define PATH_H

# include "minishell.h"

char	*path_to_absolute(char *cmd, t_mini *state);
char	*get_last_part_in_path(char *str);

#endif
