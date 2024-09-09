/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameechan <ameechan@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 17:25:59 by ameechan          #+#    #+#             */
/*   Updated: 2024/09/09 17:26:10 by ameechan         ###   ########.ch       */
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
	{
		free(ptr);
		return (NULL);
	}
	while (i < count * size)
	{
		*(ptr + i) = '\0';
		i++;
	}
	return ((void *)ptr);
}
/*
#include <stdio.h>
#include <string.h>
int	main(int argc, char **argv)
{
	(void)argc;
	printf("ft_calloc: %p\n", ft_calloc(atoi(argv[1]), 0));
	printf("   calloc: %p\n", calloc(atoi(argv[1]), 0));
}
*/
