/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameechan <ameechan@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 15:41:01 by ameechan          #+#    #+#             */
/*   Updated: 2023/11/22 16:24:49 by ameechan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include "libft.h"

int	ft_putnbr_hex(unsigned int nbr, char *hex_chars)
{
	int	print_len;

	print_len = 0;
	if (nbr >= 16)
		print_len += ft_putnbr_hex(nbr / 16, hex_chars);
	ft_putchar_fd(hex_chars[nbr % 16], 1);
	print_len++;
	return (print_len);
}
