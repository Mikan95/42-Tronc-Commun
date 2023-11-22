/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameechan <ameechan@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 15:00:13 by ameechan          #+#    #+#             */
/*   Updated: 2023/11/22 15:11:29 by ameechan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include "libft.h"
#include <unistd.h>

static int	ft_ptr_len(unsigned long n)
{
	int	len;

	len = 0;
	while (n > 0)
	{
		n /= 16;
		len++;
	}
	return (len);
}

static void	ft_dec_to_hex(unsigned long n)
{
	if (n >= 16)
	{
		ft_dec_to_hex(n / 16);
		ft_dec_to_hex(n % 16);
	}
	else
	{
		if (n <= 9)
			ft_putchar_fd((n + '0'), 1);
		else
			ft_putchar_fd((n - 10 + 'a'), 1);
	}
}

int	ft_putptr(unsigned long ptr)
{
	int	print_len;

	print_len = 0;
	print_len += write(1, "0x", 2);
	if (ptr == 0)
		print_len += write(1, "0", 1);
	else
	{
		ft_dec_to_hex(ptr);
		print_len += ft_ptr_len(ptr);
	}
	return (print_len);
}
