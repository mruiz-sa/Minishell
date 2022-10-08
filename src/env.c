/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manugarc <manugarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 12:26:34 by mruiz-sa          #+#    #+#             */
/*   Updated: 2022/10/08 12:53:36 by manugarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "array.h"
#include "minishell.h"

/**
 * @brief Get the index of key in the env array. -1 if it does not exist.
 *
 */
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

/**
 * @brief Builds a string in env format "key=value"
 *
 */
char	*build_env_str(char *key, char *value)
{
	char	*aux;
	char	*str;

	aux = ft_strjoin(key, "=");
	str = ft_strjoin(aux, value);
	free(aux);
	return (str);
}

/**
 * @brief Sets an environment variable
 *
 * 	Modifies a value in the env array:
 * 		set_env(&envp, "PWD", "/users/user/new_path");
 *
 * 	Adds a new var and value to the env array if it does not exist before:
 * 		set_env(&envp, "NON_EXISTENT_VAR", "value");
 *
 */
int	set_env(char ***envp, char *key, char *value)
{
	int		i;

	i = get_env_index(*envp, key);
	if (i == -1)
	{
		*envp = add_str_to_array(*envp, build_env_str(key, value));
		return (0);
	}
	free((*envp)[i]);
	(*envp)[i] = build_env_str(key, value);
	return (1);
}

/**
 * @brief Get the value of a key in the env array.
 *
 */
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

char	*expand_env_str(char *str, t_mini *state)
{
	/* TODO: To be implemented! Expand strings containing ENV variables.*/
	/* 'the user is $USER' => should return => 'The user is username'*/
	/* Also expand ~ into users home path */
	/* free up original str if expanded, and return de malloc-ed one? */
	(void)state;
	return (str);
}
