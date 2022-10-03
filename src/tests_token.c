/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_token.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manugarc <manugarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 18:57:48 by manu              #+#    #+#             */
/*   Updated: 2022/10/03 20:48:33 by manugarc         ###   ########.fr       */
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
	assert(!ft_strncmp(token->str, str, ft_strlen(str) + 1));
}

void	test_tokens(void)
{
	t_list	*tokens;

	/* 1 */
	tokens = str_to_tokens("ls");
	assert(ft_lstsize(tokens) == 1);
	assert_token(tokens, TK_CMD, "ls");
	/* 2 */
	tokens = str_to_tokens("grep \"test\"");
	assert(ft_lstsize(tokens) == 2);
	assert_token(tokens, TK_CMD, "grep");
	// assert_token(tokens->next, TK_ARG, "\"test\"");
	assert_token(tokens->next, TK_ARG, "test");
	assert(tokens->next->next == NULL);
	display_tokens(tokens);

	tokens = str_to_tokens("ls <infile -ls");
	assert(ft_lstsize(tokens) == 3);
	assert_token(tokens, TK_CMD, "ls");
	assert_token(tokens, TK_LESS, "infile");
	assert_token(tokens, TK_CMD, "ls");
}
