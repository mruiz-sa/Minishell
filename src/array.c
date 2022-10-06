/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruiz-sa <mruiz-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 10:41:24 by manugarc          #+#    #+#             */
/*   Updated: 2022/10/06 19:45:16 by mruiz-sa         ###   ########.fr       */
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

int	count_str_in_array(char **argv)
{
	int	count;

	count = 0;
	while (argv && argv[count])
		count++;
	return (count);
}

char	**add_str_to_array(char **argv, char *str)
{
	char	**new;
	int		count;
	int		i;

	count = count_str_in_array(argv);
	new = ft_malloc((count + 2) * sizeof(char *));
	i = 0;
	while (i < count && argv && argv[i])
	{
		new[i] = ft_strdup(argv[i]);
		i++;
	}
	new[i] = ft_strdup(str);
	new[i + 1] = NULL;
	free_array(argv);
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
