/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manu <manu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 18:57:48 by manu              #+#    #+#             */
/*   Updated: 2022/09/20 19:19:57 by manu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <assert.h>
#include "tests.h"

int	main(int argc, char *argv[])
{
	(void)argc;
	(void)argv;
	test_tokens();
	test_command_tables();
	return (0);
}
