/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manu <manu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 12:23:43 by mruiz-sa          #+#    #+#             */
/*   Updated: 2022/09/09 18:55:07 by manu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

typedef enum e_token_type {
	TK_NONE		= 0,
	TK_CMD			= 1,
	TK_ARG			= 2,
	TK_GREAT		= 3,
	TK_GREATGREAT	= 4,
	TK_LESS		= 5,
	TK_PIPE		= 6,
	TK_AMP			= 7,
}	t_token_type;

typedef struct s_token {
	t_token_type	type;
}	t_token;

typedef struct s_simple_cmd {
	int		argc;
	char	**argv;
	void	(*new)(struct s_simple_cmd *self, int argc, char **argv);
	char	*(*fn_test)(struct s_simple_cmd *self);
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
t_token	*lxr_get_tokens(char const *line);

#endif