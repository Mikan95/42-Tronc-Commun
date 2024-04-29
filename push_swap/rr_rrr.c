/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr_rrr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameechan <ameechan@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 23:05:23 by ameechan          #+#    #+#             */
/*   Updated: 2024/04/25 23:05:23 by ameechan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// maximises use of rr and refreshes the index of each node in both stacks
void	rotate_both(t_stack **a, t_stack **b, t_stack *cheapest_node)
{
	while (*a != cheapest_node && *b != cheapest_node->target_node)
		rr(a, b);
}

// rotates both stacks and prints the instruction rr
void	rr(t_stack **a, t_stack **b)
{
	rotate(a);
	rotate(b);
	ft_printf("rr\n");
}

// maximises use of rr and refreshes the index of each node in both stacks
void	rev_rotate_both(t_stack **a, t_stack **b, t_stack *cheapest_node)
{
	while (*a != cheapest_node
		&& *b != cheapest_node->target_node)
		rrr(a, b);
}

// reverse_rotates both stacks and prints the instruction rrr
void	rrr(t_stack **a, t_stack **b)
{
	reverse_rotate(a);
	reverse_rotate(b);
	ft_printf("rrr\n");
}
