/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manugarc <manugarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 20:04:00 by manu              #+#    #+#             */
/*   Updated: 2022/11/10 19:35:41 by manugarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STR_H
# define STR_H

char	*join_and_free(char *s1, char *s2);
char	*copy_enclosed_str(char *str);
char	*copy_escaped_str(char *str);
char	*ft_str_tolower(char *str);

#endif
