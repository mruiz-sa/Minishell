/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_skip.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manugarc <manugarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 20:04:00 by manu              #+#    #+#             */
/*   Updated: 2022/11/10 19:35:29 by manugarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STR_SKIP_H
# define STR_SKIP_H

# include "minishell.h"

char	*skip_spaces(char *str);
char	*skip_token_str(char *str, t_token_type type);
char	*skip_enclosed_str(char *str);

#endif
