/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manugarc <manugarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 12:27:46 by mruiz-sa          #+#    #+#             */
/*   Updated: 2022/10/08 12:51:54 by manugarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_H
# define ENV_H

# include "minishell.h"

char	*get_env(char **envp, char *key);
char	*expand_env_str(char *str, t_mini *state);
int		set_env(char ***envp, char *key, char *value);

#endif
