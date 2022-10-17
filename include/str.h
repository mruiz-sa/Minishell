/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruiz-sa <mruiz-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 20:04:00 by manu              #+#    #+#             */
/*   Updated: 2022/10/17 10:55:27 by mruiz-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STR_H
# define STR_H

char	*skip_char(char *str, char c);
char	*skip_spaces(char *str);
int		is_space(char c);
int		is_special_char(char c);
char	*find_char(char *str, char c);
int		check_quotes(char **str, char c);
char	*skip_token_str(char *str, t_token_type type);
char	*join_and_free(char *s1, char *s2);

#endif