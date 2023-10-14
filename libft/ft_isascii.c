/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameechan <ameechan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 14:23:06 by ameechan          #+#    #+#             */
/*   Updated: 2023/10/11 12:58:46 by ameechan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isascii(int c)
{
	if (c < 0 || c > 127)
		return (0);
	else
		return (1);
}
/* 
#include <stdio.h>
#include <ctype.h>
int	main(int argc, char **argv)
{
	(void)argc;
	printf("ft_isascii is: %d\n", ft_isascii(argv[1][0]));
	printf("isascii is: %d\n", isascii(argv[1][0]));
}
 */