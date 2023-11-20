/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameechan <ameechan@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 14:13:13 by ameechan          #+#    #+#             */
/*   Updated: 2023/11/20 18:58:13 by ameechan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_conversion(const char *str, va_list ap)
{
	int	count;

	count = 0;
	if (*str == 'n')
	{
		write(1, "\n", 1);
		count++;
	}
	else if (*str == 'c')
		count += ft_char(va_arg(ap, int));
	else if (*str == 's')
		count += ft_str(va_arg(ap, char *));
	else if (*str == 'p')
		count += ft_ptr(va_arg(ap, void *));
	return (count);
}
/*
	else if (*str == 'd')
	else if (*str == 'i')
	else if (*str == 'u')
	else if (*str == 'x')
	else if (*str == 'X')
	else if (*str == '%')
	else
		return (-1);
*/
