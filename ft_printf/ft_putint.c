/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putint.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameechan <ameechan@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 15:30:58 by ameechan          #+#    #+#             */
/*   Updated: 2023/11/23 15:28:08 by ameechan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include <unistd.h>

int	ft_putint(int nbr, char *dec_chars)
{
	int	print_len;

	print_len = 0;
	if (nbr == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	else if (nbr < 0)
	{
		print_len += write(1, "-", 1);
		nbr = -nbr;
	}
	if (nbr >= 10)
		print_len += ft_putint(nbr / 10, dec_chars);
	if (ft_char(dec_chars[nbr % 10]) < 0)
		return (-1);
	print_len++;
	return (print_len);
}
