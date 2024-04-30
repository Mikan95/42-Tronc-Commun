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

// checks if top_node is at the top of given stack
void	prep_for_push(t_stack **lst, t_stack *top_node, bool is_a)
{
	while (*lst != top_node)
		send_cheapest_to_top(lst, top_node, is_a);
}

// ensures top_node is at the top of given stack
void	send_cheapest_to_top(t_stack **lst, t_stack *top_node, bool is_a)
{
	if (top_node->above_median)
	{
		if (is_a)
			ra(lst);
		else
			rb(lst);
	}
	else
	{
		if (is_a)
			rra(lst);
		else
			rrb(lst);
	}
}
