/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameechan <ameechan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 13:23:34 by ameechan          #+#    #+#             */
/*   Updated: 2023/10/11 12:57:37 by ameechan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalpha(int c)
{
	if (c >= 'A' && c <= 'Z')
	{
		return (1);
	}
	else if (c >= 'a' && c <= 'z')
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
/* 
#include <stdio.h>
#include <ctype.h>
int	main(int argc, char **argv)
{
	(void)argc;
	printf("ft_isalpha is: %d\n", ft_isalpha(argv[1][0]));
	printf("isalpha is: %d\n", isalpha(argv[1][0]));
}
 */