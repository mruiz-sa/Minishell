/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manu <manu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 18:55:48 by manu              #+#    #+#             */
/*   Updated: 2022/09/24 15:00:30 by manu             ###   ########.fr       */
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
		exit_with_memory_error(NULL);
	ft_memset(ptr, 0, size);
	return (ptr);
}
