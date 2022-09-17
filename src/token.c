/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruiz-sa <mruiz-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 17:14:58 by mruiz-sa          #+#    #+#             */
/*   Updated: 2022/09/17 16:36:31 by mruiz-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "error.h"
#include "malloc.h"
#include "libft.h"
#include "str.h"

#include <stdio.h>
#include <stdlib.h>

static t_token_type	get_token_type(char *str)
{
	t_token_type	type;

	type = TK_NONE;
	if (str && *str == '|')
		type = TK_PIPE;
	else if (str && *str == '>' && *(str + 1) == '>')
		type = TK_GREATGREAT;
	else if (str && *str == '>')
		type = TK_GREAT;
	else if (str && *str == '<')
		type = TK_LESS;
	else if (str && *str == '&')
		type = TK_AMP;
	return (type);
}

char	*get_token_str(char *str, t_token_type type)
{
	char	quote;

	if (type == TK_ARG && (*str == '\'' || *str == '\"'))
	{
		quote = *str;
		return (ft_strcpy_until(++str, quote));
	}
	return (ft_strcpy_until(str, ' '));
}

static int	create_token(t_list	**tokens, char *str, t_token_type type)
{
	t_token	*token;

	token = ft_malloc(sizeof(t_token));
	token->str = get_token_str(str, type);
	if (type != TK_NONE)
		token->type = type;
	else
		token->type = get_token_type(str);
	if (token->type != TK_NONE)
	{
		ft_lstadd_back(tokens, ft_lstnew(token));
		return (1);
	}
	free(token);
	return (0);
}

static void	free_node_content(void *content)
{
	t_token	*token;

	token = content;
	if (!token)
		return ;
	if (token->str != NULL)
		free(token->str);
	free(token);
}

void	free_tokens(t_list *tokens)
{
	if (!tokens)
		return ;
	ft_lstclear(&tokens, free_node_content);
}

t_token	*get_token(t_list *token_node)
{
	if (token_node && token_node->content)
		return ((t_token *)token_node->content);
	return (NULL);
}

t_cmd_type	get_cmd_type(char *str)
{
	if (ft_strnstr(str, "echo", ft_strlen("echo")))
		return (CMD_ECHO);
	else if (ft_strnstr(str, "cd", ft_strlen("cd")))
		return (CMD_CD);
	else if (ft_strnstr(str, "pwd", ft_strlen("pwd")))
		return (CMD_PWD);
	else if (ft_strnstr(str, "export", ft_strlen("export")))
		return (CMD_EXPORT);
	else if (ft_strnstr(str, "unset", ft_strlen("unset")))
		return (CMD_UNSET);
	else if (ft_strnstr(str, "env", ft_strlen("env")))
		return (CMD_ENV);
	else if (ft_strnstr(str, "exit", ft_strlen("exit")))
		return (CMD_EXIT);
	return (CMD_NONE);
}

/* echo hi | cd test | pwd >> outfile.txt > outfile2.txt < infile & */
t_list	*str_to_tokens(char *str)
{
	t_list	*tokens;
	int		can_be_cmd;

	tokens = NULL;
	can_be_cmd = 1;
	while (str && *str)
	{
		str = skip_char(str, ' ');
		if (*str == '|' || *str == '>' || *str == '<' || *str == '&')
		{
			create_token(&tokens, str, TK_NONE);
			str++;
			if (*str == '>')
				str++;
			can_be_cmd = 1;
		}
		else
		{
			if (can_be_cmd && get_cmd_type(str))
			{
				create_token(&tokens, str, TK_CMD);
				can_be_cmd = 0;
			}
			else if (*str)
			{
				create_token(&tokens, str, TK_ARG);
				can_be_cmd = 0;
			}
			str = find_char(str, ' ');
		}
	}
	return (tokens);
}

void	display_tokens(t_list	*tokens)
{
	t_token	*token;

	while (tokens)
	{
		token = get_token(tokens);
		printf("Token is type %d, str = %s\n", token->type, token->str);
		tokens = tokens->next;
	}
}

int	validate_syntax_tokens(t_list *tokens)
{
	(void)tokens;
	return (1);
}
