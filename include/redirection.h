/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manugarc <manugarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 19:37:46 by manu              #+#    #+#             */
/*   Updated: 2022/10/15 11:07:23 by manugarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REDIRECTION_H
# define REDIRECTION_H

# include "minishell.h"
# include "libft.h"

t_redirection	*get_redirection(t_list *redirection_node);
void			free_redirections(t_list *redirections);
void			display_redirections(t_list	*redirections);
void			apply_redirections(t_list	*redirections);

#endif
