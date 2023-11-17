/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameechan <ameechan@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 13:57:04 by ameechan          #+#    #+#             */
/*   Updated: 2023/11/17 14:53:53 by ameechan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int	i;
	int	res;

	i = 0;
	res = 0;
	va_start(ap, str);
	while(str[i])
	{
		if (str[i] == '%')
			res += ft_conversion(&str[++i], ap);
		else if (ft_isprint(str[i]))
			ft_putchar_fd(str[i], 1);
		i++;
	}
	return (res + i);
}
