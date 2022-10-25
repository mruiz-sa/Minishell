/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manu <manu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 12:27:46 by mruiz-sa          #+#    #+#             */
/*   Updated: 2022/10/25 20:00:25 by manu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_H
# define ENV_H

# include "minishell.h"

char	*get_env(char **envp, char *key);
char	*get_env_dup(char **envp, char *key);
char	*expand_env_str(char *str, t_mini *state);
char	**set_env(char **envp, char *key, char *value);

#endif
