/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manugarc <manugarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 18:59:53 by manu              #+#    #+#             */
/*   Updated: 2022/09/17 10:36:39 by manugarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKEN_H
# define TOKEN_H

# include "minishell.h"
# include "libft.h"

t_list	*str_to_tokens(char *str);
t_token	*get_token(t_list *token_node);
void	free_tokens(t_list *tokens);
void	display_tokens(t_list	*tokens);
int		validate_syntax_tokens(t_list *tokens);

#endif
