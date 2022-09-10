/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manu <manu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 20:04:00 by manu              #+#    #+#             */
/*   Updated: 2022/09/10 20:04:50 by manu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STR_H
# define STR_H

char	*skip_char(char *str, char c);
char	*find_char(char *str, char c);
int		check_quotes(char **str, char c);

#endif