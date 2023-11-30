/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putint.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameechan <ameechan@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 15:30:58 by ameechan          #+#    #+#             */
/*   Updated: 2023/11/30 13:45:14 by ameechan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include <unistd.h>

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
