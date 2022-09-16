/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manu <manu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 18:55:48 by manu              #+#    #+#             */
/*   Updated: 2022/09/16 21:04:32 by manu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "error.h"
#include "libft.h"

void	*ft_malloc(int size)
{
	void	*ptr;

	ptr = malloc(size);
	if (!ptr)
		exit_with_memory_error();
	ft_memset(ptr, 0, size);
	return (ptr);
}

void	ft_free_array(char **array)
{
	int	i;

	i = 0;
	while (array && array[i])
	{
		free(array[i]);
		i++;
	}
	if (array)
		free(array);
}
