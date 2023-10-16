/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameechan <ameechan@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 16:13:57 by ameechan          #+#    #+#             */
/*   Updated: 2023/10/16 16:18:43 by ameechan         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

unsigned long	ft_strlen(char *s)
{
	int	len;

	len = 0;
	while (s[len] != '\0')
		len++;
	return (len);
}

int	ft_strlcat(char *dest, char *src, int size)
{
	int	i;
	int j;
	int	src_len;
	int	dest_len;
	
	i = 0;
	j = 0;
	src_len = ft_strlen(src);
	dest_len = ft_strlen(dest);
	if (size > 0 && dest_len < size)
	{
		while (dest[i] != '\0')
		i++;
		while (j < size - dest_len - 1 && src[j] != '\0')
		{
			dest[i + j] = src[j];
			j++;
		}
		dest[i + j] = '\0';
		return(src_len + dest_len);
	}
	else
		return(src_len + size);
}
/* 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(int argc, char** argv)
{
	(void)argc;
 	char dest[atoi(argv[3])];
	char dest2[atoi(argv[3])];
	char *src = argv[1];
	char *src2 = argv[1];
	int	res;
	int res2;

	strcpy(dest, argv[2]);
	strcpy(dest2, argv[2]);
	printf("BEFORE STRLCAT:\n");
	printf("ft_strlcat src: %s\n", src);
	printf("   strlcat src: %s\n", src2);
	printf("ft_strlcat dst: %s\n", dest);
	printf("   strlcat dst: %s\n", dest2);
	printf("##########################\n");
	res = ft_strlcat(dest, src, atoi(argv[4]));
	res2 = strlcat(dest2, src2, atoi(argv[4]));
	printf("AFTER STRLCAT:\n");
	printf("ft_strlcat src: %s\n", src);
	printf("   strlcat src: %s\n", src2);
	printf("ft_strlcat dst: %s\n", dest);
	printf("   strlcat dst: %s\n", dest2);
	printf("##########################\n");
	printf("RETURN VALUES:\n");
	printf("ft_strlcat: %d\n", res);
	printf("   strlcat: %d\n", res2);
} */