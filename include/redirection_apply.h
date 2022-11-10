/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection_apply.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manugarc <manugarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 19:37:46 by manu              #+#    #+#             */
/*   Updated: 2022/11/10 20:11:06 by manugarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REDIRECTION_APPLY_H
# define REDIRECTION_APPLY_H

# include "minishell.h"
# include "libft.h"

void			apply_redirections(t_list	*redirections, t_mini *state);

#endif
