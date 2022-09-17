/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manugarc <manugarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 10:41:24 by manugarc          #+#    #+#             */
/*   Updated: 2022/09/17 10:54:31 by manugarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft.h"
#include "malloc.h"
#include "token.h"

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
	ft_free_array(argv);
	return (new);
}
