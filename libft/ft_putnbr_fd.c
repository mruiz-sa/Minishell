/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruiz-sa <mruiz-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 17:32:04 by mruiz-sa          #+#    #+#             */
/*   Updated: 2022/04/14 18:33:02 by mruiz-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/* 
void	ft_putnbr_fd(int n);

int	main(void)
{
	int c;

	c = 156322;
	ft_putnbr_fd(c);
} */

void	ft_putnbr_fd(int n, int fd)
{
	long int	num;

	num = n;
	if (0 > num)
	{
		write(fd, "-", 1);
		num = -num;
	}
	if (num >= 10)
	{
		ft_putnbr_fd(num / 10, fd);
	}
	ft_putchar_fd((num % 10) + '0', fd);
}
