/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manugarc <manugarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 12:27:46 by mruiz-sa          #+#    #+#             */
/*   Updated: 2022/11/10 20:18:52 by manugarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_H
# define ENV_H

# include "minishell.h"

char	*get_env(char **envp, char *key);
char	*get_env_dup(t_mini *state, char **envp, char *key);
char	**set_env(char **envp, char *key, char *value);

#endif
