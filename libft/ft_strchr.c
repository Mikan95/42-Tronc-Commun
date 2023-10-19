/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameechan <ameechan@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 22:22:59 by ameechan          #+#    #+#             */
/*   Updated: 2023/10/19 16:57:39 by ameechan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			return ((char *)&str[i]);
		else
			i++;
	}
	return (0);
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
