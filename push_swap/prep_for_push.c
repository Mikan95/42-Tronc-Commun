/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prep_for_push.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameechan <ameechan@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 00:18:00 by ameechan          #+#    #+#             */
/*   Updated: 2024/04/26 00:18:00 by ameechan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//checks if top_node is at the top of given stack
//if not, ensures top_node is at the top of given stack
void	prep_for_push(t_stack **lst, t_stack *top_node, bool is_a)
{
	if(is_a)
	{
		printf("prep_for_push:\n");
		printf("top of stack: %ld\n", (*lst)->value);
		printf("cheapest_node and target: %ld -> %ld\n", top_node->value, top_node->target_node->value);
	}
	while ((*lst)->value != top_node->value)
	{
		if (is_a)
		{
			if (top_node->above_median)
				ra(lst);
			else
				rra(lst);
		}
		else if (!(is_a))
		{
			if (top_node->above_median)
				rb(lst);
			else
				rrb(lst);
		}
	}
	if(is_a)
		printf("top of stack after rotations: %ld\n", (*lst)->value);
}
