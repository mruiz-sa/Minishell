/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manu <manu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 21:16:07 by manu              #+#    #+#             */
/*   Updated: 2022/10/05 21:18:17 by manu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_builtin_type	get_builtin_type(char *str)
{
	if (ft_strnstr(str, "echo", ft_strlen("echo")))
		return (BLT_ECHO);
	else if (ft_strnstr(str, "cd", ft_strlen("cd")))
		return (BLT_CD);
	else if (ft_strnstr(str, "pwd", ft_strlen("pwd")))
		return (BLT_PWD);
	else if (ft_strnstr(str, "export", ft_strlen("export")))
		return (BLT_EXPORT);
	else if (ft_strnstr(str, "unset", ft_strlen("unset")))
		return (BLT_UNSET);
	else if (ft_strnstr(str, "env", ft_strlen("env")))
		return (BLT_ENV);
	else if (ft_strnstr(str, "exit", ft_strlen("exit")))
		return (BLT_EXIT);
	return (BLT_NONE);
}
