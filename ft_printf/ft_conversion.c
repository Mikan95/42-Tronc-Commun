/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameechan <ameechan@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 14:13:13 by ameechan          #+#    #+#             */
/*   Updated: 2023/11/21 16:24:43 by ameechan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_conversion(const char *str, va_list ap)
{
	int	count;

	count = 0;
	if (*str == 'n')
		count += write(1, "\n", 1);
	else if (*str == '%')
		count += write(1, "%", 1);
	else if (*str == 'c')
		count += ft_char(va_arg(ap, int));
	else if (*str == 's')
		count += ft_str(va_arg(ap, char *));
	else if (*str == 'p')
		count += ft_putptr(va_arg(ap, uintptr_t));
	else if (*str == 'd' || *str == 'i')
		count += ft_putint(va_arg(ap, int));
	else if (*str == 'x')
		count += ft_hex_lower(va_arg(ap, int));
	else if (*str == 'X')
		count += ft_hex_upper(va_arg(ap, int));
	else if (*str == 'u')
		count += ft_putunsigned(va_arg(ap, unsigned long));
	return (count);
}
/*
	else
		return (-1);
*/
