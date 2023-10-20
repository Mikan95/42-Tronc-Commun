/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameechan <ameechan@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 17:22:32 by ameechan          #+#    #+#             */
/*   Updated: 2023/10/20 15:34:32 by ameechan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int		i;
	char	cc;
	char	*res;

	i = 0;
	cc = (char)c;
	res = NULL;
	while (str[i])
	{
		if (str[i] == cc)
			res = (char *)&str[i];
		i++;
	}
	if (!str[i] && cc == '\0')
		return ((char *)&str[i]);
	return (res);
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
