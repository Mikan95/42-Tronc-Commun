/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameechan <ameechan@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 17:21:23 by ameechan          #+#    #+#             */
/*   Updated: 2023/10/19 16:58:37 by ameechan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		c = c - 32;
	return (c);
}
/*
#include <stdio.h>
#include <ctype.h>
int main(int argc, char **argv)
{
    (void)argc;
    printf("ft_toupper: %c\n", ft_toupper(argv[1][0]));
    printf("   toupper: %c\n", toupper(argv[1][0]));
} */
