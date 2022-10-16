/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_token.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manu <manu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 18:57:48 by manu              #+#    #+#             */
/*   Updated: 2022/10/16 12:47:00 by manu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <assert.h>

#include "minishell.h"
#include "token.h"
#include "libft.h"

static void	assert_token(t_list	*tokens, t_token_type type, char *str)
{
	t_token	*token;

	assert(tokens != NULL);
	token = get_token(tokens);
	assert(token != NULL);
	assert(token->type == type);
	if (str)
		assert(!ft_strncmp(token->str, str, ft_strlen(str) + 1));
	else
		assert(token->str == NULL);
}

static void	assert_arg_quotes(t_list *tokens, char quote)
{
	t_token	*token;

	(void)quote;
	assert(tokens != NULL);
	token = get_token(tokens);
	assert(token != NULL);
	if (quote == '\'')
		assert(token->single_quote == 1);
	else if (quote == '\"')
		assert(token->double_quote == 1);
}


void	test_tokens(void)
{
	t_list	*tokens;

	/* 1 Execute simple command absolute, no args */
	tokens = str_to_tokens("ls");
	assert(ft_lstsize(tokens) == 1);
	assert_token(tokens, TK_CMD, "ls");
	/* 2 Test an empty command */
	tokens = str_to_tokens("");
	assert(ft_lstsize(tokens) == 0);
	/* 3 test only spaces or tabs */
	tokens = str_to_tokens(" ");
	assert(ft_lstsize(tokens) == 0);
	tokens = str_to_tokens("	");
	assert(ft_lstsize(tokens) == 0);
	tokens = str_to_tokens(" 		 	 	 	 	 ");
	assert(ft_lstsize(tokens) == 0);
	/* 4 Test abs cmd with args, no quotes */
	tokens = str_to_tokens("/bin/ls -la");
	assert(ft_lstsize(tokens) == 2);
	assert_token(tokens, TK_CMD, "/bin/ls");
	assert_token(tokens->next, TK_ARG, "-la");
	assert(tokens->next->next == NULL);
	// /* 5 */
	tokens = str_to_tokens("grep \"double quoted\"");
	assert(ft_lstsize(tokens) == 2);
	assert_token(tokens, TK_CMD, "grep");
	assert_token(tokens->next, TK_ARG, "double quoted");
	assert_arg_quotes(tokens->next, '\"');
	tokens = str_to_tokens("grep \'single quoted\'");
	assert(ft_lstsize(tokens) == 2);
	assert_token(tokens->next, TK_ARG, "single quoted");
	assert_arg_quotes(tokens->next, '\'');
	// /* 6 */
	// tokens = str_to_tokens("ls < infile -ls");
	tokens = str_to_tokens("ls -ls > outfile");
	assert(ft_lstsize(tokens) == 4);
	assert_token(tokens, TK_CMD, "ls");
	assert_token(tokens->next, TK_ARG, "-ls");
	assert_token(tokens->next->next, TK_GREAT, ">");
	assert_token(tokens->next->next->next, TK_ARG, "outfile");
	tokens = str_to_tokens("ls >file");
	assert(ft_lstsize(tokens) == 3);
	assert_token(tokens, TK_CMD, "ls");
	assert_token(tokens->next, TK_GREAT, ">");
	assert_token(tokens->next->next, TK_ARG, "file");
	// /* 7 */
	tokens = str_to_tokens("< infile cat");
	assert(ft_lstsize(tokens) == 3);
	assert_token(tokens, TK_LESS, "<");
	assert_token(tokens->next, TK_ARG, "infile");
	assert_token(tokens->next->next, TK_CMD, "cat");
}
