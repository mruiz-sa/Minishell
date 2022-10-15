/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manugarc <manugarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 19:34:01 by manu              #+#    #+#             */
/*   Updated: 2022/10/15 11:06:38 by manugarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>

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

static int	get_open_flags(t_redirection *redirection)
{
	if (!redirection)
		return (O_RDONLY);
	if (redirection->type == TK_GREAT)
		return (O_CREAT | O_WRONLY | O_TRUNC);
	if (redirection->type == TK_GREATGREAT)
		return (O_CREAT | O_WRONLY | O_APPEND);
	if (redirection->type == TK_LESS)
		return (O_RDONLY);
	// if (redirection->type == TK_GREAT)
	// 	return (NULL);
	return (O_RDONLY);
}

void	apply_redirections(t_list	*redirections)
{
	t_redirection	*redirection;

	while (redirections)
	{
		redirection = get_redirection(redirections);
		redirection->fd = open(redirection->file, get_open_flags(redirection),
				S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
		if (redirection->type == TK_GREAT || redirection->type == TK_GREATGREAT)
			dup2(redirection->fd, STDOUT_FILENO);
		else if (redirection->type == TK_LESS)
			dup2(redirection->fd, STDIN_FILENO);
		close(redirection->fd);
		redirections = redirections->next;
	}
}
