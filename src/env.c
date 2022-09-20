/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manu <manu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 12:26:34 by mruiz-sa          #+#    #+#             */
/*   Updated: 2022/09/20 15:13:01 by manu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*get_env(char **envp, char *key)
{
	int		i;

	i = 0;
	while (envp[i])
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
