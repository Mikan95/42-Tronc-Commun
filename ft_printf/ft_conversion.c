/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameechan <ameechan@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 14:13:13 by ameechan          #+#    #+#             */
/*   Updated: 2023/11/17 16:22:10 by ameechan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_conversion(const char *str, va_list ap)
{
	int	count;

	count = 0;
	if (*str == 'c')
		count += ft_c(va_arg(ap, int));
	return (count);
}
/*
	else if (*str == 's')
	else if (*str == 'p')
	else if (*str == 'd')
	else if (*str == 'i')
	else if (*str == 'u')
	else if (*str == 'x')
	else if (*str == 'X')
	else if (*str == '%')
	else
		return (-1);
*/
