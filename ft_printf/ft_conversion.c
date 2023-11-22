/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameechan <ameechan@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 14:13:13 by ameechan          #+#    #+#             */
/*   Updated: 2023/11/22 17:08:00 by ameechan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_conversion(const char *str, va_list ap)
{
	int	count;

	count = 0;
	if (*str == '%')
		count += write(1, "%", 1);
	else if (*str == 'c')
		count += ft_char(va_arg(ap, int));
	else if (*str == 's')
		count += ft_str(va_arg(ap, char *));
	else if (*str == 'p')
		count += ft_putptr(va_arg(ap, unsigned long));
	else if (*str == 'd' || *str == 'i')
		count += ft_putint(va_arg(ap, int), "0123456789");
	else if (*str == 'x')
		count += ft_putnbr_hex(va_arg(ap, unsigned int), "0123456789abcdef");
	else if (*str == 'X')
		count += ft_putnbr_hex(va_arg(ap, unsigned int), "0123456789ABCDEF");
	else if (*str == 'u')
		count += ft_putnbr_dec(va_arg(ap, unsigned int), "0123456789");
	else
		return (-1);
	return (count);
}

/* 	if (*str == 'n')
		count += write(1, "\n", 1); */
