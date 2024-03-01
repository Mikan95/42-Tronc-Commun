/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameechan <ameechan@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 13:19:26 by ameechan          #+#    #+#             */
/*   Updated: 2024/03/01 13:21:48 by ameechan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		res;
	int		temp;

	res = 0;
	va_start(ap, str);
	while (*str)
	{
		if (*str == '%')
		{
			temp = ft_conversion(++str, ap);
			if (temp < 0)
				return (-1);
			res += temp;
		}
		else
		{
			if (ft_char(*str) < 0)
				return (-1);
			res++;
		}
		str++;
	}
	va_end(ap);
	return (res);
}

int	ft_conversion(const char *str, va_list ap)
{
	int	count;

	count = 0;
	if (*str == '%')
		count = write(1, "%", 1);
	else if (*str == 'c')
		count = ft_char(va_arg(ap, int));
	else if (*str == 's')
		count = ft_str(va_arg(ap, char *));
	else if (*str == 'p')
		count = ft_putptr(va_arg(ap, unsigned long), "0123456789abcdef");
	else if (*str == 'd' || *str == 'i')
		count = ft_putint(va_arg(ap, int), "0123456789");
	else if (*str == 'x')
		count = ft_putnbr_hex(va_arg(ap, unsigned int), "0123456789abcdef");
	else if (*str == 'X')
		count = ft_putnbr_hex(va_arg(ap, unsigned int), "0123456789ABCDEF");
	else if (*str == 'u')
		count = ft_putnbr_dec(va_arg(ap, unsigned int), "0123456789");
	else
		return (-1);
	return (count);
}

int	ft_str(char *str)
{
	int	print_len;

	print_len = 0;
	if (!str)
	{
		print_len += ft_str("(null)");
		if (print_len < 0)
			return (-1);
	}
	else
	{
		while (*str)
		{
			if (ft_char(*str) < 0)
				return (-1);
			print_len++;
			str++;
		}
	}
	return (print_len);
}

int	ft_putnbr_hex(unsigned int nbr, char *hex_chars)
{
	int	print_len;

	print_len = 0;
	if (nbr >= 16)
	{
		print_len += ft_putnbr_hex(nbr / 16, hex_chars);
		if (print_len < 0)
			return (-1);
	}
	if (ft_char(hex_chars[nbr % 16]) < 0)
		return (-1);
	print_len++;
	return (print_len);
}

int	ft_putnbr_dec(unsigned int nbr, char *dec_chars)
{
	int	print_len;

	print_len = 0;
	if (nbr >= 10)
	{
		print_len += ft_putnbr_dec(nbr / 10, dec_chars);
		if (print_len < 0)
			return (-1);
	}
	if (ft_char(dec_chars[nbr % 10]) < 0)
		return (-1);
	print_len++;
	return (print_len);
}
