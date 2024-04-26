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

//checks that both stacks have cheapest_node at top
void	prep_for_push(t_stack **lst, t_stack *top_node)
{
	if (*lst != top_node)
		send_cheapest_to_top(lst, top_node);
}

//ensures cheapest_node and target_node are at the top of each stack
void	send_cheapest_to_top(t_stack **lst, t_stack *top_node)
{
		if (top_node->above_median)
				rotate(lst);
		else
				reverse_rotate(lst);
}
