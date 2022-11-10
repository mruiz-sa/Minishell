/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_display.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manugarc <manugarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 10:41:24 by manugarc          #+#    #+#             */
/*   Updated: 2022/11/10 19:02:58 by manugarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft.h"
#include "malloc.h"
#include "token.h"

void	display_array(char **array)
{
	int	count;

	count = 0;
	while (array && array[count])
	{
		printf("%s\n", array[count]);
		count++;
	}
}
