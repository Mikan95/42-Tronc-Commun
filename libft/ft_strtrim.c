/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameechan <ameechan@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 15:13:49 by ameechan          #+#    #+#             */
/*   Updated: 2023/10/23 16:35:56 by ameechan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
size_t	ft_strlen(const char *s)
{
	int	len;

	len = 0;
	while (s[len] != '\0')
		len++;
	return (len);
}
 */
static unsigned int	ft_startindex(char *s1, char *set)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	while (set[j])
	{
		if (s1[i] == set[j])
		{
			i++;
			j = 0;
		}
		else
			j++;
	}
	return (i);
}

static unsigned int	ft_endindex(char *s1, char *set)
{
	unsigned int	i;
	unsigned int	j;

	i = ft_strlen(s1) - 1;
	j = 0;
	while (set[j] && i > 0)
	{
		if (s1[i] == set[j])
		{
			i--;
			j = 0;
		}
		else
			j++;
	}
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	unsigned int	i;
	unsigned int	start;
	unsigned int	end;
	char			*ptr;

	i = 0;
	start = ft_startindex((char *)s1, (char *)set);
	end = ft_endindex((char *)s1, (char *)set);
	if (start > end)
		ptr = (char *)malloc(1 * sizeof(char));
	else
		ptr = (char *)malloc((end - start + 2) * sizeof(char));
	if (!ptr)
		return (NULL);
	while (start <= end)
	{
		ptr[i] = s1[start];
		start++;
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
/*
#include <stdio.h>

int	main(int argc, char **argv)
{
	(void)argc;
	printf("String: %s\n", argv[1]);
	printf("Characters to trim: %s\n", argv[2]);
	printf("Trimmed string: %s\n", ft_strtrim(argv[1], argv[2]));
}
 */
