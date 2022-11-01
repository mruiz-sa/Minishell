/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_expand.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manu <manu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 10:19:01 by manugarc          #+#    #+#             */
/*   Updated: 2022/11/01 16:15:50 by manu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "token.h"
#include "env.h"
#include "malloc.h"
#include "path.h"
#include "str.h"

#define TILDE '~'

static int	is_expandable_arg(char *str)
{
	int		n_escapes;
	int		mod;

	mod = 0;
	if (!ft_strchr(str, '$'))
		return (0);
	n_escapes = 0;
	while (str && *str)
	{
		if (*str == '\\')
			n_escapes++;
		else
		{
			if (*str == '$')
			{
				mod = n_escapes % 2;
				if (!mod)
					return (1);
			}
			n_escapes = 0;
		}
		str++;
	}
	return (0);
}

static int	count_tilde(char *str)
{
	int		count;
	char	prev;

	count = 0;
	prev = 0;
	while (str && *str)
	{
		if (*str == TILDE && prev != TILDE && *(str + 1) != TILDE)
			count++;
		str++;
	}
	return (count);
}

static char	*expand_tilde(char *str, char *home)
{
	char	*expanded;
	char	*aux;
	char	prev;

	if (!ft_strchr(str, TILDE) || !count_tilde(str))
		return (str);
	expanded = (char *)ft_malloc(
			(count_tilde(str) * ft_strlen(home)) + ft_strlen(str) + 1);
	prev = 0;
	aux = str;
	while (str && *str)
	{
		if (*str == TILDE && prev != TILDE && *(str + 1) != TILDE)
			ft_strlcpy(expanded, home, ft_strlen(home) + 1);
		else
			expanded[ft_strlen(expanded)] = *str;
		str++;
	}
	free(aux);
	return (expanded);
}

void	expand_token_strings(t_list *tokens, t_mini *state)
{
	t_token	*token;

	while (tokens)
	{
		token = get_token(tokens);
		if (!token->ignore)
		{
			if (token->type == TK_CMD)
				token->str = path_to_absolute(token->str, state);
			else if (token->type == TK_ARG && !token->single_quote)
			{
				while (is_expandable_arg(token->str))
					token->str = expand_env_str(token->str, state);
			}
			if (token->type == TK_ARG
				&& !token->single_quote && !token->double_quote)
				token->str = expand_tilde(token->str,
						get_env(state->envp, "HOME"));
		}
		tokens = tokens->next;
	}
}
