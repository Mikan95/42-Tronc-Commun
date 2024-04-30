/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameechan <ameechan@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 16:37:45 by ameechan          #+#    #+#             */
/*   Updated: 2024/04/30 15:42:15 by ameechan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* sorts stack of size 4 or bigger by progressively pushing from A to B
while simultaneously sorting B in ascending order.
Then sorts last three elements in A and pushes everyhting back from B
in ascending order */
void	sort_stacks(t_stack **a, t_stack **b)
{
	int	len_a;

	len_a = ft_lstsize(*a);
	if (len_a-- > 3 && !is_sorted(*a))
		pb(a, b);
	if (len_a-- > 3 && !is_sorted(*a))
		pb(a, b);
	while (len_a-- > 3 && !is_sorted(*a))
	{
		init_nodes_a(*a, *b);
		push_a_to_b(a, b);
	}
	sort_three(a);
	while (*b)
	{
		init_nodes_b(*a, *b);
		push_b_to_a(a, b);
	}
	set_index(*a);
	min_to_top(a);
}

// sets indexes, sets target_nodes and finds and sets cheapest_node for stack_a
void	init_nodes_a(t_stack *a, t_stack *b)
{
	set_index(a);
	set_index(b);
	set_target_a(a, b);
	find_cheapest(a, b);
	set_cheapest(a);
}

// sets indexes, sets target_nodes and finds and sets cheapest_node for stack_a
void	init_nodes_b(t_stack *a, t_stack *b)
{
	set_index(a);
	set_index(b);
	set_target_b(a, b);
}

// pushes the cheapest node from stack a to stack b
void	push_a_to_b(t_stack **a, t_stack **b)
{
	t_stack	*cheapest_node;

	cheapest_node = get_cheapest(*a);
	if (cheapest_node->above_median
		&& cheapest_node->target_node->above_median)
		rotate_both(a, b, cheapest_node);
	else if (!(cheapest_node->above_median)
		&& !(cheapest_node->target_node->above_median))
		rev_rotate_both(a, b, cheapest_node);
	prep_for_push(a, cheapest_node, true);
	prep_for_push(b, cheapest_node->target_node, false);
	pb(a, b);
	set_index(*a);
	set_index(*b);
}

// pushes top element of stack b above target_node of stack a
void	push_b_to_a(t_stack **a, t_stack **b)
{
	prep_for_push(a, (*b)->target_node, true);
	pa(b, a);
}
