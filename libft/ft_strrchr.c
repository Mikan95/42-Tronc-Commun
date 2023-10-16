/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameechan <ameechan@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 22:44:36 by ameechan          #+#    #+#             */
/*   Updated: 2023/10/16 22:50:24 by ameechan         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

char *ft_strrchr(char *str, int c)
{
    int i;
    char *ptr;

    i = 0;
    while(str[i] != '\0')
    {
        if (str[i] == c)
        {
            ptr = &str[i];
        }
        else
        i++;
    }
    if (ptr == str)
    return(ptr);
    else
    return ('\0');
}

#include <stdio.h>
#include <bsd/string.h>

int main(int argc, char **argv)
{
    (void)argc;
    printf("ft_strrchr: %s\n", ft_strrchr(argv[1], argv[2][0]));
    printf("   strrchr: %s\n", strrchr(argv[1], argv[2][0]));
}