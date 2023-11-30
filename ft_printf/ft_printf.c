/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameechan <ameechan@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 13:57:04 by ameechan          #+#    #+#             */
/*   Updated: 2023/11/30 13:08:28 by ameechan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		res;
	int		temp;

	res = 0;
	va_start(ap, str);
	while (*str)
	{
		if (*str == '%')
		{
			temp = ft_conversion(++str, ap);
			if (temp < 0)
				return (-1);
			res += temp;
		}
		else
		{
			if (ft_char(*str) < 0)
				return (-1);
			res++;
		}
		str++;
	}
	va_end(ap);
	return (res);
}
/*
void	ft_test(unsigned long test, int n)
{
	printf("\n----\n");
	printf("Test %d\n", n);
	printf("----\n");
	fflush(stdout);
	printf("printf:\n");
	fflush(stdout);
	printf("%d\n", printf("%lu\n", test));
	fflush(stdout);
	printf("ft_printf:\n");
	fflush(stdout);
	printf("%d\n", ft_printf("%u\n", test));
	fflush(stdout);
	printf("\n----\n");
}

int	main()
{
//	char			test1 = 'c';
//	char			*test2 = "Hello, Zoe!";
//	void			*test3 = &test2;
 	int				test4 =  2147483647;
	int				test5 = -2147483648;
	unsigned long	test6 = 4294967295;
	unsigned long	test7 = 9223372036854775807;
	unsigned long	test8 = -9223372036854775807;

 	ft_test(test4, 1);
	ft_test(test5, 2);
	ft_test(test6, 3);
	ft_test(test7, 4);
	ft_test(test8, 5);
	printf("END OF TESTS\n");
}

	printf("\n----\n");
	printf("Test 1\n");
	printf("----\n");
	fflush(stdout);
	printf("printf:\n");
	fflush(stdout);
	printf("%d\n", printf("%u\n", test1));
	fflush(stdout);
	printf("ft_printf:\n");
	fflush(stdout);
	printf("%d\n", ft_printf("%u\n", test1));
	fflush(stdout);
	printf("\n----\n");
	printf("Test 2\n");
	printf("----\n");
	fflush(stdout);
	printf("printf:\n");
	fflush(stdout);
	printf("%d\n", printf("%s\n", test2));
	fflush(stdout);
	printf("ft_printf:\n");
	fflush(stdout);
	printf("%d\n", ft_printf("%s\n", test2));
	fflush(stdout);
	printf("\n----\n");
	printf("Test 3\n");
	printf("----\n");
	fflush(stdout);
	printf("printf:\n");
	fflush(stdout);
	printf("%d\n", printf("%p\n", test3));
	fflush(stdout);
	printf("ft_printf:\n");
	fflush(stdout);
	printf("%d\n", ft_printf("%p\n", test3));
	fflush(stdout);
	printf("\n----\n");
	printf("Test 4\n");
	printf("----\n");
	fflush(stdout);
	printf("printf:\n");
	fflush(stdout);
	printf("%d\n", printf("%d\n", test4));
	fflush(stdout);
	printf("ft_printf:\n");
	fflush(stdout);
	printf("%d\n", ft_printf("%d\n", test4));
	fflush(stdout);
	printf("\n----\n");
	printf("Test 5\n");
	printf("----\n");
	fflush(stdout);
	printf("printf:\n");
	fflush(stdout);
	printf("%d\n\n", printf("%d\n", test5));
	fflush(stdout);
	printf("ft_printf:\n");
	fflush(stdout);
	printf("%d\n", ft_printf("%d\n", test5));
	printf("\n----\n");
	printf("Test 6\n");
	printf("----\n");
	fflush(stdout);
	printf("printf:\n");
	fflush(stdout);
	printf("%d\n\n", printf("%%,%c\n", test1));
	fflush(stdout);
	printf("ft_printf:\n");
	fflush(stdout);
	printf("%d\n", ft_printf("%%,%c\n", test1));
}
 */
