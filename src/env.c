/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manu <manu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 12:26:34 by mruiz-sa          #+#    #+#             */
/*   Updated: 2022/09/24 17:18:21 by manu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "array.h"

int	get_env_index(char **envp, char *key)
{
	int		i;
	int		key_len;

	i = 0;
	key_len = ft_strlen(key);
	while (envp && envp[i])
	{
		if (!ft_strncmp(envp[i], key, key_len) && envp[i][key_len] == '=')
			return (i);
		i++;
	}
	return (-1);
}

int	set_env(char **envp, char *key, char *value)
{
	int		i;
	char	*aux;

	i = get_env_index(envp, key);
	if (i == -1)
		return (0);
	free(envp[i]);
	aux = ft_strjoin(key, "=");
	envp[i] = ft_strjoin(aux, value);
	free(aux);
	return (1);
}

char	*get_env(char **envp, char *key)
{
	int		i;

	i = 0;
	while (envp && envp[i])
	{
		if (!ft_strncmp(envp[i], key, ft_strlen(key)))
			return (ft_strchr(envp[i], '=') + 1);
		i++;
	}
	return (NULL);
}

char	*expand_env_str(char *str)
{
	/* TODO: To be implemented! Expand strings containing ENV variables.*/
	/* 'the user is $USER' => should return => 'The user is username'*/
	/* Also expand ~ into users home path */
	/* free up original str if expanded, and return de malloc-ed one? */
	return (str);
}

char	**duplicate_envp(char **envp)
{
	return (duplicate_array(envp));
}
