/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameechan <ameechan@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 13:22:05 by ameechan          #+#    #+#             */
/*   Updated: 2024/03/01 13:23:19 by ameechan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_ptr_hex(unsigned long nbr, char *hex_chars)
{
	int	print_len;

	print_len = 0;
	if (nbr >= 16)
	{
		print_len += ft_ptr_hex(nbr / 16, hex_chars);
		if (print_len < 0)
			return (-1);
	}
	if (ft_char(hex_chars[nbr % 16]) < 0)
		return (-1);
	print_len++;
	return (print_len);
}

int	ft_putptr(unsigned long ptr, char *hex_chars)
{
	int	print_len;

	print_len = 0;
	print_len = ft_str("0x");
	if (print_len < 0)
		return (-1);
	print_len += ft_ptr_hex(ptr, hex_chars);
	if (print_len < 0)
		return (-1);
	return (print_len);
}

static int	ft_int_min(void)
{
	if (write(1, "-2147483648", 11) != 11)
		return (-1);
	return (11);
}

int	ft_putint(int nbr, char *dec_chars)
{
	int	print_len;

	print_len = 0;
	if (nbr == -2147483648)
		print_len = ft_int_min();
	else
	{
		if (nbr < 0)
		{
			if (ft_char('-') < 0)
				return (-1);
			print_len++;
			nbr *= -1;
		}
		if (nbr >= 10)
		{
			print_len += ft_putint(nbr / 10, dec_chars);
			if (print_len < 0)
				return (-1);
		}
		if (ft_char(dec_chars[nbr % 10]) < 0)
			return (-1);
		print_len++;
	}
	return (print_len);
}

int	ft_char(char c)
{
	if (write(1, &c, 1) != 1)
		return (-1);
	return (1);
}
