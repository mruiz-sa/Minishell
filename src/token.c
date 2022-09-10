/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manu <manu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 17:14:58 by mruiz-sa          #+#    #+#             */
/*   Updated: 2022/09/10 20:08:26 by manu             ###   ########.fr       */
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

static int	create_token_special(t_list	**tokens, char *str)
{
	t_token	*token;

	token = ft_malloc(sizeof(t_token));
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
	if (!content)
		return ;
	free(content);
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

//
//  lexer converts state->readline into array of tokens (t_token in minishell.h)
// 		quick test: line = "ls -a a* | grep test > outfile.txt"
// 		token = ls, type cmd
// 		token = -a, type arg
// 		token = a*, type arg (expandable wildcard)
// 		token = |, type pipe (fork process)
// 		token = grep, type cmd
// 		token = test, arg
// 		token = >, type great (redirection)
//
// ls -a | grep test >> outfile.txt > outfile2.txt < infile &
t_list	*str_to_tokens(char *str)
{
	t_list	*tokens;

	tokens = NULL;
	while (str && *str)
	{
		str = skip_char(str, ' ');
		if (*str == '|' || *str == '>' || *str == '<' || *str == '&')
		{
			create_token_special(&tokens, str);
			str++;
			if (*str == '>')
				str++;
		}
		else
		{
			// if (check_quotes(&str, '\"')
			// 	|| check_quotes(&str, '\'') || *str)
			// 	num_w++;
			// str = find_char(str, ' ');
			str++;
		}
	}
	return (tokens);
}
