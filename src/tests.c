/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manu <manu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 18:57:48 by manu              #+#    #+#             */
/*   Updated: 2022/10/16 12:37:32 by manu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <assert.h>
#include "tests.h"

int	main(int argc, char *argv[])
{
	(void)argc;
	(void)argv;
	printf("Running tests...!\n\n");
	test_tokens();
	test_command_tables();
	printf("All test ran OK!\n\n");
	return (0);
}
