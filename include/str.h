/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manu <manu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 20:04:00 by manu              #+#    #+#             */
/*   Updated: 2022/10/31 17:17:15 by manu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STR_H
# define STR_H

char	*skip_spaces(char *str);
int		is_space(char c);
int		is_special_char(char c);
char	*skip_token_str(char *str, t_token_type type);
char	*join_and_free(char *s1, char *s2);
char	*copy_enclosed_str(char *str);
char	*skip_enclosed_str(char *str);
char	*copy_escaped_str(char *str);

#endif