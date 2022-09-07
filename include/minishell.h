/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manu <manu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 12:23:43 by mruiz-sa          #+#    #+#             */
/*   Updated: 2022/09/07 21:59:45 by manu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

typedef enum e_token_type {
	NONE		= 0,
	CMD			= 1,
	ARG			= 2,
	GREAT		= 3,
	GREATGREAT	= 4,
	LESS		= 5,
	PIPE		= 6,
	AMP			= 7,
}	t_token_type;

typedef struct s_token {
	t_token_type	type;
}	t_token;

typedef struct s_simple_cmd {
	int		argc;
	char	**argv;
}	t_simple_cmd;

typedef struct s_cmd {
	int				ncmds;
	t_simple_cmd	**cmds;
	void			*outFile;
	void			*inFile;
	void			*errFile;
	int				background;
}	t_cmd;

typedef struct s_prompt {
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
char	*ft_read(t_mini *state);
int		free_state(t_mini *state);
int		free_prompt(t_prompt *prompt);
char	**ft_lexer(char const *str, char c);

#endif