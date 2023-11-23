/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameechan <ameechan@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 15:00:13 by ameechan          #+#    #+#             */
/*   Updated: 2023/11/23 15:47:50 by ameechan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
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

static int	ft_ptr_hex(unsigned long nbr, char *hex_chars)
{
	if (nbr >= 16)
		ft_ptr_hex(nbr / 16, hex_chars);
	if (ft_char(hex_chars[nbr % 16]) < 0)
		return (-1);
	return (0);
}

int	ft_putptr(unsigned long ptr, char *hex_chars)
{
	int	print_len;

	print_len = 0;
	print_len += write(1, "0x", 2);
	if (ptr == 0)
		print_len += write(1, "0", 1);
	else
	{
		if (ft_ptr_hex(ptr, hex_chars) < 0)
			return (-1);
		print_len += ft_ptr_len(ptr);
	}
	return (print_len);
}
