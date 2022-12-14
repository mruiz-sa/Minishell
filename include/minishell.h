/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manugarc <manugarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 12:23:43 by mruiz-sa          #+#    #+#             */
/*   Updated: 2022/11/10 20:08:11 by manugarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft.h"

# define FD_IN 0
# define FD_OUT 1

unsigned char	g_exec_ret;

typedef enum e_token_type {
	TK_NONE			= 0,
	TK_CMD			= 1,
	TK_ARG			= 2,
	TK_GREAT		= 3,
	TK_GREATGREAT	= 4,
	TK_LESS			= 5,
	TK_LESSLESS		= 6,
	TK_PIPE			= 7,
	TK_AMP			= 8,
}	t_token_type;

typedef struct s_token {
	t_token_type	type;
	char			*str;
	int				double_quote;
	int				single_quote;
	int				ignore;
}	t_token;

typedef enum e_builtin_type {
	BLT_NONE	= 0,
	BLT_ECHO	= 1,
	BLT_CD		= 2,
	BLT_PWD		= 3,
	BLT_EXPORT	= 4,
	BLT_UNSET	= 5,
	BLT_ENV		= 6,
	BLT_EXIT	= 7,
}	t_builtin_type;

typedef struct s_redirection {
	t_token_type	type;
	char			*file;
	int				fd;
}	t_redirection;

typedef struct s_simple_cmd {
	int				argc;
	char			**argv;
	char			**argv_quoted;
	t_builtin_type	builtin_type;
	int				fd_in;
	int				fd_out;
	int				fd_error;
	t_list			*redirections;
	pid_t			pid;
	int				pipe_fds[2];
}	t_simple_cmd;

typedef struct s_cmd {
	int		ncmds;
	t_list	*cmds;
	int		background;
}	t_cmd;

typedef struct s_prompt {
	char	*user;
	char	*prompt;
	char	*pwd;
}	t_prompt;

typedef struct s_mini {
	t_prompt		prompt;
	char			*readline;
	char			**envp;
}	t_mini;

void	get_prompt(char **envp, t_prompt *prompt);
char	*ft_read(t_mini *state);
int		free_state(t_mini *state);
int		free_prompt(t_prompt *prompt);
void	free_array(char **array);

#endif
