/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameechan <ameechan@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 21:09:18 by ameechan          #+#    #+#             */
/*   Updated: 2023/10/18 21:35:21 by ameechan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static unsigned long	ft_strlen(char *s)
{
	int	len;

	len = 0;
	while (s[len] != '\0')
		len++;
	return (len);
}

char	*ft_strdup(const char *s1)
{
	int		i;
	int		len;
	char	*ptr;

	i = 0;
	len = ft_strlen((char *)s1);
	ptr = (char *)malloc(len * sizeof(char));
	if (ptr)
	{
		while (i < len)
		{
			ptr[i] = s1[i];
			i++;
		}
	}
	else
		ptr = NULL;
	return (ptr);
}
/*
#include <stdio.h>
#include <string.h>
int	main(int argc, char **argv)
{
	(void)argc;
	printf("ft_strdup: %s\n", ft_strdup(argv[1]));
	printf("   strdup: %s\n", strdup(argv[1]));
}
 */
