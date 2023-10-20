/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameechan <ameechan@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 19:25:58 by ameechan          #+#    #+#             */
/*   Updated: 2023/10/20 15:16:03 by ameechan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t len)
{
	unsigned char	*ptr1;
	unsigned char	*ptr2;
	size_t			i;

	i = 0;
	ptr1 = (unsigned char *) dest;
	ptr2 = (unsigned char *) src;
	while (i < len)
	{
		ptr1[i] = ptr2[i];
		i++;
	}
	return (dest);
}
/*
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(int argc, char** argv)
{
	(void)argc;
	char dest1[100] = "";
	char dest2[100] = "";
	char *src1 = "I love Zoe";
	char *src2 = "I love Zoe";
	printf("ft_memcpy: %s\n", ft_memcpy(dest1, src1, atoi(argv[1])));
	printf("   memcpy: %s\n", memcpy(dest2, src2, atoi(argv[1])));
}
 */
