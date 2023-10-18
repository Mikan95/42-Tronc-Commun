/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameechan <ameechan@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 19:41:15 by ameechan          #+#    #+#             */
/*   Updated: 2023/10/18 20:53:06 by ameechan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
void	*ft_calloc(unsigned int count, unsigned int size)
{
	unsigned int	i;
	int				*ptr;

	i = 0;
	ptr = NULL;
	if ((int)count < 0 || (int)size < 0)
		return((void *)ptr);
	else
	{
		ptr = (void *)malloc(count * size);
		if (ptr)
		{
			while (i < count)
			{
				*(ptr + i)= '\0';
				i++;
			}
		}
	}
	return((void *)ptr);
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
