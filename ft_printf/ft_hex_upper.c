/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex_upper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameechan <ameechan@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 15:30:58 by ameechan          #+#    #+#             */
/*   Updated: 2023/11/21 16:19:24 by ameechan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <unistd.h>
#include "libft.h"

static int	ft_intlen(int n)
{
	int	len;

	len = 0;
	if (n == 0)
		len += write(1, "0", 1);
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static void	ft_dec_to_hex(int n)
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
			ft_putchar_fd((n - 10 + 'A'), 1);
	}
}

int	ft_hex_upper(int n)
{
	int	print_len;

	print_len = 0;
	if (n == 0)
		print_len += write(1, "0", 1);
	else
	{
		ft_dec_to_hex(n);
		print_len += ft_intlen(n);
	}
	return (print_len);
}
