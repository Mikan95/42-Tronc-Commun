/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameechan <ameechan@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 15:43:37 by ameechan          #+#    #+#             */
/*   Updated: 2023/10/19 16:57:35 by ameechan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *dest, int n, size_t len)
{
	unsigned char	*ptr;
	unsigned long	i;

	i = 0;
	ptr = (unsigned char *) dest;
	while (i++ <= len)
		*ptr++ = n;
	return (dest);
}
/*
#include <string.h>
#include <stdio.h>
int	main(int argc, char** argv)
{
	(void)argc;
	printf("ft_memset does: %s\n", ft_memset(argv[1], argv[2][0], argv[3][0]));
	printf("memset does: %s\n", memset(argv[1], argv[2][0],  argv[3][0]));
}
*/
