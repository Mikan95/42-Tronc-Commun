/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameechan <ameechan@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 22:44:36 by ameechan          #+#    #+#             */
/*   Updated: 2023/10/17 01:37:59 by ameechan         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

unsigned long	ft_strlen(char *s)
{
	int	len;

	len = 0;
	while (s[len] != '\0')
		len++;
	return (len);
}

char *ft_strrchr(char *str, int c)
{
    int i;

    i = ft_strlen(str);
    while(i >= 0)
    {
        if (str[i] == c)
        return (&str[i]);
        else
        i--;
    }
    return ('\0');
}
/* 
#include <stdio.h>
#include <bsd/string.h>

int main(int argc, char **argv)
{
    (void)argc;
    printf("ft_strrchr: %s\n", ft_strrchr(argv[1], argv[2][0]));
    printf("   strrchr: %s\n", strrchr(argv[1], argv[2][0]));
} */