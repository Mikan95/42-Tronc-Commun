/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameechan <ameechan@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 15:03:26 by ameechan          #+#    #+#             */
/*   Updated: 2023/10/20 14:46:02 by ameechan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	int	len;

	len = 0;
	while (s[len] != '\0')
		len++;
	return (len);
}
/*
#include <string.h>
#include <stdio.h>
int	main(int argc, char **argv)
{
	(void)argc;
	printf("ft_strlen of string is: %lu\n", ft_strlen(argv[1]));
	printf("strlen of string is: %lu\n", strlen(argv[1]));
}
*/
