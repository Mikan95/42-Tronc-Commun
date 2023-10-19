/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameechan <ameechan@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 15:41:26 by ameechan          #+#    #+#             */
/*   Updated: 2023/10/19 16:57:13 by ameechan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	int				res1;
	int				res2;
	unsigned char	*ptr1;
	unsigned char	*ptr2;

	res1 = 0;
	res2 = 0;
	ptr1 = (unsigned char *)s1;
	ptr2 = (unsigned char *)s2;
	while (n-- > 0)
	{
		if (*ptr1 != *ptr2)
		{
			res1 = *ptr1;
			res2 = *ptr2;
			break ;
		}
		ptr1++;
		ptr2++;
	}
	return (res1 - res2);
}
/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int argc, char **argv)
{
    (void)argc;
    printf("ft_memcmp: %d\n", ft_memcmp(argv[1], argv[2], atoi(argv[3])));
    printf("   memcmp: %d\n", memcmp(argv[1], argv[2], atoi(argv[3])));
} */
