/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manu <manu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 12:23:43 by mruiz-sa          #+#    #+#             */
/*   Updated: 2022/09/16 21:03:42 by manu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft.h"

typedef enum e_token_type {
	TK_NONE			= 0,
	TK_CMD			= 1,
	TK_ARG			= 2,
	TK_GREAT		= 3,
	TK_GREATGREAT	= 4,
	TK_LESS			= 5,
	TK_PIPE			= 6,
	TK_AMP			= 7,
}	t_token_type;

typedef struct s_token {
	t_token_type	type;
	char			*str;
	struct s_token	*next;
	struct s_token	*prev;
}	t_token;

typedef enum e_cmd_type {
	CMD_NONE	= 0,
	CMD_ECHO	= 1,
	CMD_CD		= 2,
	CMD_PWD		= 3,
	CMD_EXPORT	= 4,
	CMD_UNSET	= 5,
	CMD_ENV		= 6,
	CMD_EXIT	= 7,
}	t_cmd_type;

typedef struct s_simple_cmd {
	t_cmd_type			type;
	int					argc;
	char				**argv;
	struct s_simple_cmd	*next;
	struct s_simple_cmd	*prev;
}	t_simple_cmd;

typedef struct s_cmd {
	int		ncmds;
	t_list	*cmds;
	void	*outFile;
	void	*inFile;
	void	*errFile;
	int		background;
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
char	*ft_strcpy_until(char *str, char until);
int		free_state(t_mini *state);
int		free_prompt(t_prompt *prompt);
char	**ft_lexer(char *str, char c);
t_token	*lxr_get_tokens(char *line);
void	free_array(char **array);
void	exec_cmd(char *cmd, t_mini *state);

#endif
