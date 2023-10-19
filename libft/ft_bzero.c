/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameechan <ameechan@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 18:04:52 by ameechan          #+#    #+#             */
/*   Updated: 2023/10/19 16:56:21 by ameechan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	ft_bzero(void *str, size_t n)
{
	unsigned char	*ptr;
	unsigned long	i;

	i = 0;
	ptr = (unsigned char *)str;
	if (n != '\0')
		while (i <= n)
			ptr[i++] = '\0';
}
/*
#include <stdio.h>
#include <strings.h>
int	main(int argc, char **argv)
{
	(void)argc;
	printf("ft_bzero does: %s\n", ft_bzero(argv[1], '0'));
	printf("bzero does: %s\n", bzero(argv[2], '0'));
}
*/
/* ft_bzero() et bzero() utilisent des argv different pour verifier
 qu'ils font bel et bien la meme chose.
 Il faut juste s'assurer d'écrire le meme str pour les deux
 */
