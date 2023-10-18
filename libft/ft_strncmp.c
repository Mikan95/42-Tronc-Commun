/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameechan <ameechan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 06:21:42 by ameechan          #+#    #+#             */
/*   Updated: 2023/10/18 17:07:28 by ameechan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Calculates len of both str and returns the shortest one,
unless one of both len = 0
*/
unsigned long	ft_shortestlen(char *s1, char *s2)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s1[i] != '\0')
		i++;
	while (s2[j] != '\0')
		j++;
	if (i >= j && j != 0)
		return (j);
	else if (j >= i && i != 0)
		return (i);
	else if (i == 0 && j > i)
		return (j);
	else if (j == 0 && i > j)
		return (i);
	else
		return (0);
}

int	ft_strncmp(const char *str1, const char *str2, int n)
{
	int	i;
	int	res1;
	int	res2;
	int	len;

	i = 0;
	res1 = 0;
	res2 = 0;
	len = ft_shortestlen((char *)str1, (char *)str2);
	while (i < n && i < len)
	{
		if (str1[i] == str2[i])
		{
			res1 = res1 + str1[i];
			res2 = res2 + str2[i];
			i++;
		}
		else
		{
			res1 = res1 + str1[i];
			res2 = res2 + str2[i];
			break ;
		}
	}
	return (res1 - res2);
}
/* 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int argc, char **argv)
{
    (void)argc;
    printf("ft_strncmp: %d\n", ft_strncmp(argv[1], argv[2], atoi(argv[3])));
    printf("   strncmp: %d\n", strncmp(argv[1], argv[2], atoi(argv[3])));
}
*/