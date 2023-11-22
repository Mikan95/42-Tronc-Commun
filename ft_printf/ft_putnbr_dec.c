/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_dec.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameechan <ameechan@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 15:41:01 by ameechan          #+#    #+#             */
/*   Updated: 2023/11/22 16:35:42 by ameechan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include "libft.h"

int	ft_putnbr_dec(unsigned int nbr, char *dec_chars)
{
	int	print_len;

	print_len = 0;
	if (nbr >= 10)
		print_len += ft_putnbr_dec(nbr / 10, dec_chars);
	ft_putchar_fd(dec_chars[nbr % 10], 1);
	print_len++;
	return (print_len);
}
