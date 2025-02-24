/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameechan <ameechan@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 14:35:14 by ameechan          #+#    #+#             */
/*   Updated: 2023/10/19 16:56:55 by ameechan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	else
		return (0);
}
/*
#include <stdio.h>
#include <ctype.h>
int	main(int argc, char **argv)
{
	(void)argc;
	printf("ft_isprint is: %d\n", ft_isprint(argv[1][0]));
	printf("isprint is: %d\n", isprint(argv[1][0]));
}
 */
/*
#include <stdio.h>
int	main()
{
	int c = 127;
	printf("%d", ft_isprint(c));
}
*/
