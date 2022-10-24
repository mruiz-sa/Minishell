/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manu <manu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 10:44:12 by manugarc          #+#    #+#             */
/*   Updated: 2022/10/24 19:14:47 by manu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_H
# define ARRAY_H

void	free_array(char **array);
int		count_str_in_array(char **array);
char	**add_str_to_array(char **array, char *str);
char	**duplicate_array(char **array);
void	display_array(char **array);
char	**del_str_from_array(char **array, char *str);

#endif
