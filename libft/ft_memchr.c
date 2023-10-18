/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameechan <ameechan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 09:22:45 by ameechan          #+#    #+#             */
/*   Updated: 2023/10/18 17:11:14 by ameechan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_memchr(void *str, int c, int n)
{
	unsigned char	*ptr;

	ptr = (unsigned char *)str;
	while (n-- > 0)
	{
		if (*ptr == (unsigned char)c)
		{
			return (ptr);
			ptr++;
		}
	}
	return ('\0');
}
/* 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int argc, char **argv)
{
    (void)argc;
    void *res1 = ft_memchr(argv[1], argv[2][0], strlen(argv[1]));
    void *res2 = memchr(argv[1], argv[2][0], strlen(argv[1]));
    if (res1 == res2)
    printf("Both same:\n%p \n%p\n", res1, res2);
    else
    printf("Results differ:\n%p \n%p\n", res1, res2);
} */