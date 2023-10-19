/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameechan <ameechan@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 17:22:32 by ameechan          #+#    #+#             */
/*   Updated: 2023/10/19 15:25:43 by ameechan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static size_t	ft_strlen(const char *s)
{
	int	len;

	len = 0;
	while (s[len] != '\0')
		len++;
	return (len);
}

char	*ft_strrchr(const char *str, int c)
{
	int	i;

	i = ft_strlen(str);
	while (i >= 0)
	{
		if (str[i] == c)
			return ((char *)&str[i]);
		else
			i--;
	}
	return (0);
}
/*
#include <stdio.h>
#include <string.h>

int main(int argc, char **argv)
{
	(void)argc;
	printf("ft_strrchr: %s\n", ft_strrchr(argv[1], argv[2][0]));
	printf("   strrchr: %s\n", strrchr(argv[1], argv[2][0]));
}
*/
