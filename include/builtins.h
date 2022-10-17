/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manu <manu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 09:59:14 by manugarc          #+#    #+#             */
/*   Updated: 2022/10/17 22:58:48 by manu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

# include "minishell.h"

t_builtin_type	get_builtin_type(char *str);
int				is_parent_builtin(t_builtin_type type);
int				run_builtin(t_list *cmds);

#endif
