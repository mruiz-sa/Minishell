/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manugarc <manugarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 12:26:34 by mruiz-sa          #+#    #+#             */
/*   Updated: 2022/11/10 20:18:18 by manugarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "array.h"
#include "minishell.h"
#include "str.h"

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
static char	*build_env_str(char *key, char *value)
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
 * 		envp = set_env(envp, "PWD", "/users/user/new_path");
 *
 * 	Adds a new var and value to the env array if it does not exist before:
 * 		envp = set_env(envp, "NON_EXISTENT_VAR", "value");
 *
 */
char	**set_env(char **envp, char *key, char *value)
{
	char	*str;
	int		i;

	i = get_env_index(envp, key);
	if (i == -1)
	{
		str = build_env_str(key, value);
		envp = add_str_to_array(envp, str);
		free(str);
		return (envp);
	}
	free(envp[i]);
	envp[i] = build_env_str(key, value);
	return (envp);
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

char	*get_env_dup(t_mini *state, char **envp, char *key)
{
	char	*value;

	(void)state;
	if (!key || !*key)
		return (ft_strdup(""));
	if (!ft_strncmp(key, "?", 1))
		return (ft_itoa(g_exec_ret));
	value = get_env(envp, key);
	if (!value)
		return (ft_strdup(""));
	return (ft_strdup(value));
}
