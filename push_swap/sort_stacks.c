/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameechan <ameechan@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 16:37:45 by ameechan          #+#    #+#             */
/*   Updated: 2024/04/22 16:44:21 by ameechan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_stacks(t_stack **a, t_stack **b)
{
	int	len_a;

	len_a = ft_lstsize(*a);
	if (len_a-- > 3 && !is_sorted(*a))
		push(a, b);
	if (len_a-- > 3 && !is_sorted(*a))
		push(a, b);
	while (len_a-- > 3 && !is_sorted(*a))
//	{
		init_nodes_a(*a, *b);
//		push_a_to_b(a, b);
/* 	}
	sort_three(a);
	while(*b)
	{
		init_nodes_b(*a, *b);
		push_b_to_a(a, b);
	}
	set_index(*a);
	min_to_top(a);*/
}

void	init_nodes_a(t_stack *a, t_stack *b)
{
	set_index(a);
	set_index(b);
	set_target_a(a, b);
	find_cheapest_push(a, b);
	set_cheapest(a);
}
