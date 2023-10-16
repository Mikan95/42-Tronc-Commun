/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameechan <ameechan@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 21:43:24 by ameechan          #+#    #+#             */
/*   Updated: 2023/10/16 22:02:24 by ameechan         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

int ft_toupper(unsigned char c)
{
    if (c >= "a" && c <= "z")
        c = c - 32;
    return (c);
}

#include <stdio.h>
#include <ctype.h>
int main(int argc, char **argv)
{
    printf("ft_toupper: %c", ft_toupper(argv[1][0]));
    printf("   toupper: %c", toupper(argv[1][0]));
}