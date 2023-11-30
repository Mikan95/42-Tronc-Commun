/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_dec.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameechan <ameechan@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 15:41:01 by ameechan          #+#    #+#             */
/*   Updated: 2023/11/30 13:14:33 by ameechan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	ft_putnbr_dec(unsigned int nbr, char *dec_chars)
{
	int	print_len;

	print_len = 0;
	if (nbr >= 10)
	{
		print_len += ft_putnbr_dec(nbr / 10, dec_chars);
		if (print_len < 0)
			return (-1);
	}
	if (ft_char(dec_chars[nbr % 10]) < 0)
		return (-1);
	print_len++;
	return (print_len);
}
