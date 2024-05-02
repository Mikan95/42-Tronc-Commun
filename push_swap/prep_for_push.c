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

/* checks if top_node is at the top of given stack
if not, ensures top_node is at the top of given stack */
void	prep_a_for_push(t_stack **a, t_stack *top_node)
{
	while (*a != top_node)
	{
		if (top_node->above_median)
			ra(a);
		else
			rra(a);
	}
}

/* checks if top_node is at the top of given stack
if not, ensures top_node is at the top of given stack */
void	prep_b_for_push(t_stack **b, t_stack *top_node)
{
	while (*b != top_node)
	{
		if (top_node->above_median)
			rb(b);
		else
			rrb(b);
	}
}
