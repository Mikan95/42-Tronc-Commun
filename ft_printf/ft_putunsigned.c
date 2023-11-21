/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameechan <ameechan@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 16:23:47 by ameechan          #+#    #+#             */
/*   Updated: 2023/11/21 17:17:02 by ameechan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <unistd.h>

static void	ft_putunsigned_fd(unsigned long n, int fd)
{
	if (n >= 0 && n <= 9)
	{
		n += 48;
		write (fd, &n, 1);
	}
	else
	{
		ft_putunsigned_fd(n / 10, fd);
		ft_putunsigned_fd(n % 10, fd);
	}
}

static int	ft_intlen(unsigned long n)
{
	int	len;

	len = 0;
	if (n == 0)
		len += 1;
	while (n > 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

int	ft_putunsigned(unsigned long n)
{
	int	print_len;

	print_len = ft_intlen(n);
	ft_putunsigned_fd(n, 1);
	return (print_len);
}
