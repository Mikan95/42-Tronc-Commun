/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameechan <ameechan@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 17:19:54 by ameechan          #+#    #+#             */
/*   Updated: 2023/10/19 16:58:33 by ameechan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		c = c + 32;
	return (c);
}

/* #include <stdio.h>
#include <ctype.h>
int main(int argc, char **argv)
{
    (void)argc;
    printf("ft_tolower: %c\n", ft_tolower(argv[1][0]));
    printf("   tolower: %c\n", tolower(argv[1][0]));
} */
