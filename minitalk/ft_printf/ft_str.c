/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameechan <ameechan@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 15:34:18 by ameechan          #+#    #+#             */
/*   Updated: 2023/11/30 13:28:50 by ameechan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_str(char *str)
{
	int	print_len;

	print_len = 0;
	if (!str)
	{
		print_len += ft_str("(null)");
		if (print_len < 0)
			return (-1);
	}
	else
	{
		while (*str)
		{
			if (ft_char(*str) < 0)
				return (-1);
			print_len++;
			str++;
		}
	}
	return (print_len);
}
