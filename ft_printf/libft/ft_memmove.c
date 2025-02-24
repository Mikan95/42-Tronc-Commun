/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameechan <ameechan@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 20:15:13 by ameechan          #+#    #+#             */
/*   Updated: 2023/10/23 13:49:46 by ameechan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ovrlap(unsigned char *ptrd, unsigned char *ptrs, int len, int i)
{
	while (i <= len)
	{
		ptrd[len - i] = ptrs[len - i];
		i++;
	}
}

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	unsigned char	*ptrd;
	unsigned char	*ptrs;
	unsigned long	i;

	i = 0;
	if (!dest && !src)
		return (0);
	ptrd = (unsigned char *) dest;
	ptrs = (unsigned char *) src;
	if (ptrs < ptrd && ((ptrs + len) >= ptrd))
		ovrlap(ptrd, ptrs, len, 1);
	else
	{
		while (i < len)
		{
			ptrd[i] = ptrs[i];
			i++;
		}
	}
	return (dest);
}
/* #include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(int argc, char** argv)
{
	(void)argc; */
/* 	########################################### */
	/* char ptr[100] = "";
	char ptr2[100] = "";
	char *str = "I love Zoe";
	char *str2 = "I love Zoe"; */
/*	########################################### */
	/* char str[] = "Hello-Zoe,you-are-beautiful";
	char str2[] = "Hello-Zoe,you-are-beautiful";
	char *ptr = &str[5];
	char *ptr2 = &str2[5]; */
/*	########################################### */
	/* printf("before memmove:\n");
	printf("ft_memmove src: %s\n", str);
	printf("   memmove src: %s\n", str2);
	printf("ft_memmove dst: %s\n", ptr);
	printf("   memmove dst: %s\n", ptr2);
	ft_memmove(ptr, str, atoi(argv[1]));
	memmove(ptr2, str2, atoi(argv[1]));
	printf("After memmove:\n");
	printf("ft_memmove src: %s\n", str);
	printf("   memmove src: %s\n", str2);
	printf("ft_memmove dst: %s\n", ptr);
	printf("   memmove dst: %s\n", ptr2);
} */
