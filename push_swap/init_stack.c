/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameechan <ameechan@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 15:44:21 by ameechan          #+#    #+#             */
/*   Updated: 2024/04/06 17:27:59 by ameechan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_stack_a(t_stack **stack_a, char **argv)
{
	int			i;
	long int	res;

	i = 0;
	while (argv[i])
	{
		res = ft_atol(argv[i]);
		ft_lstadd_back(stack_a, res);
		i++;
	}
}
