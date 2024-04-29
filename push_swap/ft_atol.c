/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameechan <ameechan@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 15:59:33 by ameechan          #+#    #+#             */
/*   Updated: 2024/04/29 15:47:39 by ameechan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//copnverts from ascii to long int
long int	ft_atol(char *str)
{
	long int	res = 0;
	long int	sign = 1;

	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		res = res * 10 + *str - '0';
		str++;
	}
	return (sign * res);
}

/* int	main (int argc, char **argv)
{
	(void)argc;
	printf("converted number: %ld\n", ft_atol(argv[1]));
}
 */
