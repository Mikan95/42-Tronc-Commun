/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameechan <ameechan@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 06:21:42 by ameechan          #+#    #+#             */
/*   Updated: 2023/10/17 09:19:09 by ameechan         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

int ft_strncmp(char *str1, char *str2, int n)
{
    int i;
    int res1;
    int res2;

    i = 0;
    res1 = 0;
    res2 = 0;
    while (i < n && str1[i])
    {
        res1 = res1 + str1[i];
        i++;
    }
    i = 0;
    while (i < n && str2[i])
    {
        res2 = res2 + str2[i];
        i++;
    }
    return(res1 - res2);
}
/* 
#include <stdio.h>
#include <stdlib.h>
#include <bsd/string.h>
int main(int argc, char **argv)
{
    (void)argc;
    printf("ft_strncmp: %d\n", ft_strncmp(argv[1], argv[2], atoi(argv[3])));
    printf("   strncmp: %d\n", strncmp(argv[1], argv[2], atoi(argv[3])));
} */