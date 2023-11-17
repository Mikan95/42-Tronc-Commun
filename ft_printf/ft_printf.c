/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameechan <ameechan@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 13:57:04 by ameechan          #+#    #+#             */
/*   Updated: 2023/11/17 16:17:44 by ameechan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int	i;
	int	res;

	i = 0;
	res = 0;
	va_start(ap, str);
	while(str[i])
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
	(void)argc;
	char	c;
	c = argv[1][0];
	printf("printf:\n");
	printf("your character is: %c\n", c);
	printf("########################\nft_printf:\n");
	ft_printf("your character is: %c\n", c);
}
