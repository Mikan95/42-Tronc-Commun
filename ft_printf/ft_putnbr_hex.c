/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameechan <ameechan@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 15:41:01 by ameechan          #+#    #+#             */
/*   Updated: 2023/11/30 13:18:15 by ameechan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

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
