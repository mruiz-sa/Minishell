/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruiz-sa <mruiz-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 12:23:43 by mruiz-sa          #+#    #+#             */
/*   Updated: 2022/09/03 12:52:55 by mruiz-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

typedef struct s_prompt{
	char	*user;
	char	*prompt;
	char	*pwd;
}	t_prompt;

typedef struct s_mini {
	t_prompt	prompt;
	char		*readline;
	char		**envp;
}	t_mini;

void	get_prompt(char **envp, t_prompt *prompt);
char	*ft_read(t_mini *state, char **envp);
int		free_state(t_mini *state);
int		free_prompt(t_prompt *prompt);

#endif