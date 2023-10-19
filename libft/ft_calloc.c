/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameechan <ameechan@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 19:41:15 by ameechan          #+#    #+#             */
/*   Updated: 2023/10/19 16:56:33 by ameechan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t			i;
	unsigned char	*ptr;

	i = 0;
	ptr = (void *)malloc(count * size);
	if (!ptr)
		return (NULL);
	while (i < count)
	{
		*(ptr + i) = '\0';
		i++;
	}
	return ((void *)ptr);
}
/*
#include <stdio.h>
int	main(int argc, char **argv)
{
	(void)argc;
	printf("ft_calloc: %p\n", ft_calloc(atoi(argv[1]), atoi(argv[2])));
	printf("   calloc: %p\n", calloc(atoi(argv[1]), atoi(argv[2])));
}
*/
