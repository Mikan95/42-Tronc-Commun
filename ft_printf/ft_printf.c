/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameechan <ameechan@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 13:57:04 by ameechan          #+#    #+#             */
/*   Updated: 2023/11/20 19:05:19 by ameechan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	int		i;
	int		res1;
	int		res2;
	va_list	ap;

	i = 0;
	res1 = 0;
	res2 = 0;
	va_start(ap, str);
	while (str[i])
	{
		if (str[i] == '%' || str[i] == '\\')
		{
			res1 += ft_conversion(&str[++i], ap);
			i++;
		}
		else
		{
			ft_putchar_fd(str[i], 1);
			res2++;
			i++;
		}
	}
	return (res1 + res2);
}
/*
int	main()
{
//	char			test1 = 'c';
	char			*test2 = "Hello, Zoe!";
	void			*test3 = &test2;
//	int				test4 = 280597;
//	int				test5 = -280597;
//	unsigned int	test6 = 2805199711;
 	printf("Test 1\n");
	fflush(stdout);
	printf("printf: %c\n", test1);
	fflush(stdout);
	ft_printf("ft_printf: %c\n", test1);
	fflush(stdout);
	printf("Test 2\n");
	fflush(stdout);
	printf("printf: %s\n", test2);
	fflush(stdout);
	ft_printf("ft_printf: %s\n", test2);
	fflush(stdout);
	printf("printf:\n");
	fflush(stdout);
	printf("%d\n", printf("%p\n", test3));
	printf("----\n");
	fflush(stdout);
	printf("ft_printf:\n");
	fflush(stdout);
	printf("%d\n", ft_printf("%p\n", test3));
}
 */
