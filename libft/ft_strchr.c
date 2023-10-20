/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameechan <ameechan@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 22:22:59 by ameechan          #+#    #+#             */
/*   Updated: 2023/10/20 14:31:04 by ameechan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	int		i;
	char	cc;

	i = 0;
	cc = (char)c;
	while (str[i])
	{
		if (str[i] == cc)
			return ((char *)&str[i]);
		i++;
	}
	if (!str[i] && cc == '\0')
		return ((char *)&str[i]);
	return (NULL);
}
/*
#include <stdio.h>
#include <string.h>

int main(int argc, char **argv)
{
    (void)argc;
    printf("ft_strchr: %s\n", ft_strchr(argv[1], argv[2][0]));
    printf("   strchr: %s\n", strchr(argv[1], argv[2][0]));
} */
