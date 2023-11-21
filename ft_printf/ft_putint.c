/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putint.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameechan <ameechan@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 15:30:58 by ameechan          #+#    #+#             */
/*   Updated: 2023/11/21 15:42:12 by ameechan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include "libft.h"

static int	ft_intlen(int n)
{
	int	len;

	len = 0;
	if (n < 0 || n == 0)
		len += 1;
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

int	ft_putint(int n)
{
	int	print_len;

	print_len = ft_intlen(n);
	ft_putnbr_fd(n, 1);
	return (print_len);
}
