/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameechan <ameechan@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 13:57:04 by ameechan          #+#    #+#             */
/*   Updated: 2023/11/17 16:30:30 by ameechan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_printf(const char *str, ...)
{
	int		i;
	int		res;
	va_list	ap;

	i = 0;
	res = 0;
	va_start(ap, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			res += ft_conversion(&str[++i], ap);
			i++;
		}
		else
			ft_putchar_fd(str[i], 1);
		i++;
	}
	return (res + i);
}

int	main(int argc, char **argv)
{
	char	c;
	int		res1;
	int		res2;

	(void)argc;
	c = argv[1][0];
	printf("printf:\n");
	res1 = printf("your character is: %c\n", c);
	printf("########################\nft_printf:\n");
	res2 = ft_printf("your character is: %c\n", c);
	printf("########################\nRETURN VALUES:");
	printf("printf: %d\nft_printf: %d\n", res1, res2);
}
