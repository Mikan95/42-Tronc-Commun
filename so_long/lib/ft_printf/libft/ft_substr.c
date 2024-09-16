/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameechan <ameechan@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 13:38:26 by ameechan          #+#    #+#             */
/*   Updated: 2024/09/16 13:38:27 by ameechan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*ptr;

	i = 0;
	if (!s)
		return (0);
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s + start))
		len = ft_strlen(s + start);
	ptr = ft_calloc(len + 1, sizeof(char));
	if (!ptr)
	{
		free(ptr);
		return (NULL);
	}
	while (i < len)
	{
		ptr[i] = s[start + i];
		i++;
	}
	return (ptr);
}
/*
#include <stdio.h>
int	main(int argc, char **argv)
{
	(void)argc;
	char	*str = argv[1];
	printf("String: %s\n", str);
	printf("Result: %s\n", ft_substr(argv[1], atoi(argv[2]), atoi(argv[3])));
}
*/
