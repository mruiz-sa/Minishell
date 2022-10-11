/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_type.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manu <manu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 19:20:29 by manu              #+#    #+#             */
/*   Updated: 2022/10/11 19:55:25 by manu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKEN_TYPE_H
# define TOKEN_TYPE_H

# include "minishell.h"

t_token_type	get_token_type(char *str);
int             is_token_redirection(t_token_type type);

#endif
