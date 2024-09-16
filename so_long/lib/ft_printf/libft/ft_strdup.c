/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameechan <ameechan@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 13:38:14 by ameechan          #+#    #+#             */
/*   Updated: 2024/09/16 13:38:16 by ameechan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	i;
	char	*ptr;

	ptr = (char *)malloc(ft_strlen(s1) + 1);
	if (!ptr)
	{
		free(ptr);
		return (NULL);
	}
	i = 0;
	while (i < ft_strlen(s1))
	{
		ptr[i] = s1[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
/*
#include <stdio.h>
#include <string.h>
int	main(int argc, char **argv)
{
	(void)argc;
	printf("ft_strdup: %p\n", ft_strdup(argv[1]));
	printf("   strdup: %p\n", strdup(argv[1]));
}
 */
