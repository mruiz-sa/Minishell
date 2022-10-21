/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manu <manu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 10:41:24 by manugarc          #+#    #+#             */
/*   Updated: 2022/10/21 19:20:13 by manu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft.h"
#include "malloc.h"
#include "token.h"

void	free_array(char **array)
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

int	count_str_in_array(char **array)
{
	int	count;

	count = 0;
	while (array && array[count])
		count++;
	return (count);
}

char	**add_str_to_array(char **array, char *str)
{
	char	**new;
	int		count;
	int		i;

	count = count_str_in_array(array);
	new = ft_malloc((count + 2) * sizeof(char *));
	i = 0;
	while (i < count && array && array[i])
	{
		new[i] = ft_strdup(array[i]);
		i++;
	}
	new[i] = ft_strdup(str);
	new[i + 1] = NULL;
	free_array(array);
	return (new);
}

char	**duplicate_array(char **array)
{
	char	**new;
	int		count;
	int		i;

	count = count_str_in_array(array);
	new = (char **) ft_malloc((count + 1) * sizeof(char *));
	i = 0;
	while (i < count && array && array[i])
	{
		new[i] = ft_strdup(array[i]);
		i++;
	}
	new[i] = NULL;
	return (new);
}

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
