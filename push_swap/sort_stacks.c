/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameechan <ameechan@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 16:37:45 by ameechan          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2024/05/01 17:14:12 by ameechan         ###   ########.fr       */
=======
/*   Updated: 2024/05/02 14:12:46 by ameechan         ###   ########.fr       */
>>>>>>> turnin
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* sorts stack of size 4 or bigger by progressively pushing from A to B
while simultaneously sorting B in ascending order.
Then sorts last three elements in A and pushes everyhting back from B
in the correct position for ascending order */
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

// sets indexes, sets target_nodes, finds and sets cheapest_node for stack_a
void	init_nodes_a(t_stack *a, t_stack *b)
{
	set_index(a);
	set_index(b);
	set_target_a(a, b);
	find_cheapest(a, b);
	set_cheapest(a);
<<<<<<< HEAD
//	printf("init_node_a cheapest node: %ld -> %ld\n", (get_cheapest(a))->value, (get_cheapest(a))->target_node->value);
/* 	printf("cheapest node & target node:\n");
	temp = a;
	while (!(temp->cheapest))
		temp = temp->next;
	printf("%ld -> %ld\n", temp->value, temp->target_node->value); */
=======
>>>>>>> turnin
}

// sets indexes and sets target_nodes for all nodes in stack_b
void	init_nodes_b(t_stack *a, t_stack *b)
{
	set_index(a);
	set_index(b);
	set_target_b(a, b);
<<<<<<< HEAD
//	printf("init_node_b nodes: %ld -> %ld\n", b->value, b->target_node->value);
=======
>>>>>>> turnin
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
<<<<<<< HEAD
	prep_for_push(a, cheapest_node, true);
	prep_for_push(b, cheapest_node->target_node, false);
//	printf("pushing %ld above %ld\n\n", (*a)->value, (*b)->value);
=======
	prep_a_for_push(a, cheapest_node);
	prep_b_for_push(b, cheapest_node->target_node);
>>>>>>> turnin
	pb(a, b);
	set_index(*a);
	set_index(*b);
}

// pushes top element of stack b above appropriate target_node in stack a
void	push_b_to_a(t_stack **a, t_stack **b)
{
<<<<<<< HEAD
	prep_for_push(a, (*b)->target_node, true);
//	printf("pushing %ld above %ld\n\n", (*b)->value, (*a)->value);
=======
	prep_a_for_push(a, (*b)->target_node);
>>>>>>> turnin
	pa(b, a);
}
