/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manu <manu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 12:27:46 by mruiz-sa          #+#    #+#             */
/*   Updated: 2022/09/24 17:47:13 by manu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_H
# define ENV_H

char	*get_env(char **envp, char *key);
char	*expand_env_str(char *str);
int		set_env(char ***envp, char *key, char *value);

#endif