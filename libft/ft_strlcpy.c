/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameechan <ameechan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 15:14:27 by ameechan          #+#    #+#             */
/*   Updated: 2023/10/14 16:00:11 by ameechan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned long	ft_strlen(char *s)
{
	int	len;

	len = 0;
	while (s[len] != '\0')
		len++;
	return (len);
}

int	ft_strlcpy(char *dest, char *src, int dest_size)
{
	int	i;
	int src_len;

	i = 0;
	src_len = ft_strlen(src);
	if (dest_size > 0)
	{
		while (i < dest_size - 1 && src[i] != '\0')
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	return(src_len);
}
/* 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(int argc, char** argv)
{
	(void)argc;
 	char dest[atoi(argv[2])];
	char dest2[atoi(argv[2])];
	char *src = argv[1];
	char *src2 = argv[1];
	int	res;
	int res2;

	printf("BEFORE STRLCPY:\n");
	printf("ft_strlcpy src: %s\n", src);
	printf("   strlcpy src: %s\n", src2);
	printf("ft_strlcpy dst: %s\n", dest);
	printf("   strlcpy dst: %s\n", dest2);
	printf("##########################\n");
	res = ft_strlcpy(dest, src, atoi(argv[2]));
	res2 = strlcpy(dest2, src2, atoi(argv[2]));
	printf("AFTER STRLCPY:\n");
	printf("ft_strlcpy src: %s\n", src);
	printf("   strlcpy src: %s\n", src2);
	printf("ft_strlcpy dst: %s\n", dest);
	printf("   strlcpy dst: %s\n", dest2);
	printf("##########################\n");
	printf("RETURN VALUES:\n");
	printf("ft_strlcpy: %d\n", res);
	printf("   strlcpy: %d\n", res2);
} */