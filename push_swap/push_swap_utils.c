/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameechan <ameechan@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 12:44:32 by ameechan          #+#    #+#             */
/*   Updated: 2024/04/12 16:10:05 by ameechan         ###   ########.fr       */
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

void	push(t_stack **src, t_stack **dest)
{
	t_stack	*dest_last;
	t_stack *dest_first;
	t_stack	*pushed_node;

	pushed_node = *src;
	pushed_node->next->prev = pushed_node->prev;
	pushed_node->prev->next = pushed_node->next;
	*src = pushed_node->next;
	if(!*dest)
	{
		*dest = pushed_node;
		pushed_node->next = NULL;
		pushed_node->prev = NULL;
	}
	else
	{
	dest_first = *dest;
	dest_last = ft_lstlast(*dest);
	pushed_node->prev = dest_last;
	pushed_node->next = *dest;
	dest_last->next = pushed_node;
	dest_first->prev = pushed_node;
	}
}
