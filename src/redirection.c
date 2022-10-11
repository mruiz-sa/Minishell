/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manu <manu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 19:34:01 by manu              #+#    #+#             */
/*   Updated: 2022/10/11 19:57:35 by manu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	free_node_content(void *content)
{
	t_redirection	*redirection;

	redirection = content;
	if (!redirection)
		return ;
	if (redirection->file != NULL)
		free(redirection->file);
	free(redirection);
}

void	free_redirections(t_list *redirections)
{
	if (!redirections)
		return ;
	ft_lstclear(&redirections, free_node_content);
}

t_redirection	*get_redirection(t_list *redirection_node)
{
	if (redirection_node && redirection_node->content)
		return ((t_redirection *)redirection_node->content);
	return (NULL);
}

void	display_redirections(t_list	*redirections)
{
	t_redirection	*redirection;

	while (redirections)
	{
		redirection = get_redirection(redirections);
		printf("Redirection is type %d, file = %s\n", redirection->type,
			redirection->file);
		redirections = redirections->next;
	}
}
