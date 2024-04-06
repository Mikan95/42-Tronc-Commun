/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameechan <ameechan@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 15:44:21 by ameechan          #+#    #+#             */
/*   Updated: 2024/04/06 17:20:19 by ameechan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_stack_a(t_stack **stack_a, char **argv)
{
	int			i;
	long int	res;
	t_stack		*new_node;

	i = 0;
	while (argv[i])
	{
		new_node = malloc(sizeof(t_stack));
		if (!new_node)
			return ;
		res = ft_atol(argv[i]);
		new_node->value = res;
		ft_lstadd_back(stack_a, new_node);
		free(new_node);
		i++;
	}
}
