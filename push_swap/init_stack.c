/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameechan <ameechan@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 15:44:21 by ameechan          #+#    #+#             */
/*   Updated: 2024/03/20 17:07:01 by ameechan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_stack_a(t_stack **stack_a, char **argv)
{
	int		i;
	t_stack	*new_node;

	i = 0;
	new_node = malloc(sizeof(t_stack));
	while (argv[i])
	{
		new_node->value = argv[i][0];
		ft_lstadd_back(stack_a, new_node);
	}
}
