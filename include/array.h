/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manugarc <manugarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 10:44:12 by manugarc          #+#    #+#             */
/*   Updated: 2022/09/17 10:54:42 by manugarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_H
# define ARRAY_H

void	ft_free_array(char **array);
int		count_str_in_array(char **argv);
char	**add_str_to_array(char **argv, char *str);

#endif
