/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameechan <ameechan@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 12:44:32 by ameechan          #+#    #+#             */
/*   Updated: 2024/04/10 17:16:56 by ameechan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//iterates through a linked list and checks if it is sorted in ascending order
int	is_sorted(t_stack *lst)
{
	t_stack	*current;

	current = lst;
	if (!lst)
		return (1);
	while (current->value < current->next->value)
		current = current->next;
	if (current->next == lst)
		return (1);
	else
		return (0);
}

//swaps the first two elements of a list
void	swap(t_stack **lst)
{
	t_stack	*first;
	t_stack	*second;

	first = *lst;
	second = first->next;
// adjust next pointers
	first->next = second->next;
	second->next->prev = first;
	second->next = first;
//adjust prev pointers
	second->prev = first->prev;
	first->prev->next = second;
	first->prev = second;
// set second node as head node
	*lst = second;
}
