/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_sanitize.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manu <manu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 18:59:53 by manu              #+#    #+#             */
/*   Updated: 2022/10/31 16:44:15 by manu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKEN_SANITIZE_H
# define TOKEN_SANITIZE_H

# include "minishell.h"

void	sanitize_token_strings(t_list *tokens, t_mini *state);

#endif
