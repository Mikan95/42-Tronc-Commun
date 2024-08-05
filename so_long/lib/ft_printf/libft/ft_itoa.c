/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameechan <ameechan@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 13:24:40 by ameechan          #+#    #+#             */
/*   Updated: 2023/11/02 16:49:22 by ameechan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_intlen(long n);
static char	*ft_negative(int n, int len, char *str);

char	*ft_itoa(int n)
{
	int		len;
	long	nbr;
	char	*str;

	nbr = (long)n;
	len = ft_intlen(nbr);
	if (nbr < 0)
		len = len + 1;
	str = ft_calloc((len + 1), sizeof(char));
	if (!str)
		return (NULL);
	if (nbr < 0)
		return (ft_negative(nbr, len, str));
	while (len > 0)
	{
		str[(len - 1)] = (nbr % 10) + '0';
		nbr = nbr / 10;
		len--;
	}
	return (str);
}

static int	ft_intlen(long n)
{
	int	len;

	len = 0;
	if (n == 0)
		len = 1;
	while (n != 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

static char	*ft_negative(int n, int len, char *str)
{
	char	int_min[12];

	ft_strlcpy(int_min, "-2147483648", 12);
	if (n == -2147483648)
		ft_strlcpy(str, int_min, 12);
	else
	{
		str[0] = '-';
		n = -n;
		while (len > 1)
		{
			str[(len - 1)] = (n % 10) + '0';
			n = n / 10;
			len--;
		}
	}
	return (str);
}
/*
int	main(int argc, char **argv)
{
	(void)argc;
	int	n;

	n = atoi(argv[1]);
	printf("Integer: %d\n", n);
	printf("Not converted: %c\n", n);
	printf("Converted: %s", ft_itoa(n));
}
*/
