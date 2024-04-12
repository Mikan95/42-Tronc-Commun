/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameechan <ameechan@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 12:44:32 by ameechan          #+#    #+#             */
/*   Updated: 2024/04/12 17:10:52 by ameechan         ###   ########.fr       */
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
	second->next = first;
// set second node as head node
	*lst = second;
}

void	push(t_stack **src, t_stack **dest)
{
	t_stack	*dest_last;
	t_stack	*pushed_node;

	if (!*src)
		return ;
	pushed_node = ft_lstadd_back(*src);
	if (!*dest)
		*dest = pushed_node;
	else
	{
		dest_last = ft_lstlast(*dest);
		dest_last->next = pushed_node;
	}
	pushed_node->next = NULL;
}

void	rotate(t_stack **lst)
{
	
}
