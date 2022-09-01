/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruiz-sa <mruiz-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 11:35:27 by mruiz-sa          #+#    #+#             */
/*   Updated: 2022/04/18 12:02:54 by mruiz-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*newnodo;

	newnodo = malloc(sizeof(t_list));
	if (!newnodo)
		return (NULL);
	newnodo->content = content;
	newnodo->next = NULL;
	return (newnodo);
}
