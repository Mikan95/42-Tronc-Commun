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
				rra(lst);
		}
	}
}
