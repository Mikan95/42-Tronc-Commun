/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameechan <ameechan@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 16:36:59 by ameechan          #+#    #+#             */
/*   Updated: 2023/11/07 17:02:03 by ameechan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

void	ft_printnbr_fd(int n, int fd)
{
	if (n >= 0 && n <= 9)
	{
		n += 48;
		write (fd, &n, 1);
	}
	else
	{
		ft_printnbr_fd(n / 10, fd);
		ft_printnbr_fd(n % 10, fd);
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
		write (fd, "-2147483648", 11);
	else if (n < 0)
	{
		write (fd, "-", 1);
		n = -n;
		ft_printnbr_fd(n, fd);
	}
	else
		ft_printnbr_fd(n, fd);
}
/*
#include <stdlib.h>
int	main(int argc, char **argv)
{
	(void)argc;
	ft_putnbr_fd(atoi(argv[1]), 1);
}
 */
