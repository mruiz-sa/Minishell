/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_prompt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manugarc <manugarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 12:10:38 by mruiz-sa          #+#    #+#             */
/*   Updated: 2022/11/04 14:08:27 by manugarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft.h"

void	get_prompt(char **envp, t_prompt *prompt)
{
	(void)envp;
	prompt->prompt = ft_strdup("minishell $ ");
}
