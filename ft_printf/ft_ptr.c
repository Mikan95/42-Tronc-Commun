/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameechan <ameechan@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 15:55:47 by ameechan          #+#    #+#             */
/*   Updated: 2023/11/20 19:04:37 by ameechan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	dec_to_hex_recursive(uintptr_t value, char *hex_str, int *index)
{
	int	remainder;

	if (value > 0)
	{
		remainder = value % 16;
		dec_to_hex_recursive(value / 16, hex_str, index);
		if (remainder < 10)
			hex_str[(*index)++] = '0' + remainder;
		else if (remainder > 9)
			hex_str[(*index)++] = 'a' + remainder - 10;
	}
}

static char	*dec_to_hex(uintptr_t value)
{
	int			length;
	int			index;
	uintptr_t	temp;
	char		*hex_str;

	length = 1;
	index = 0;
	temp = value;
	while (temp > 0)
	{
		length++;
		temp /= 16;
	}
	hex_str = (char *)malloc(length + 1);
	if (!hex_str)
		return (NULL);
	dec_to_hex_recursive(value, hex_str, &index);
	hex_str[index] = '\0';
	return (hex_str);
}

int	ft_ptr(void *ptr)
{
	char	*str;
	int		i;
	int		tmp;

	str = dec_to_hex((uintptr_t)ptr);
	tmp = ft_strlen(str);
	i = tmp -1;
	write(1, "0x", 2);
	while (str[i])
	{
		write(1, &str[i], 1);
		i--;
	}
	free(str);
	return (tmp + 2);
}
