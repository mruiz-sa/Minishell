/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manu <manu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 15:34:54 by manu              #+#    #+#             */
/*   Updated: 2022/09/24 16:26:09 by manu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*path_to_absolute(char *cmd)
{
	/* TODO: To be implemented! Check if cmd starts with / or not (absolute vs local path). */
	/* 'ls' => should return => '/bin/ls' */
	/* a cmd can also start (and use more) ... This is a relative path, it needs to get converted to absolute */
	/* if in path /users/user1/home, running '../program' should return '/users/user1/program'
	/* free up original cmd if replaced, and return de malloc-ed one? */
	/* the funciton should not validate valid path/program, only convert'*/
	return (cmd);
}
