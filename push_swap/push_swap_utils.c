/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameechan <ameechan@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 12:44:32 by ameechan          #+#    #+#             */
/*   Updated: 2024/04/15 18:52:49 by ameechan         ###   ########.fr       */
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

//swaps the top two elements of stack "lst"
void	swap(t_stack **lst)
{
	t_stack	*last_node;
	t_stack	*penultimate_node;

	last_node = ft_lstlast(*lst);
	penultimate_node = last_node->prev;
// adjust next pointers
	if (penultimate_node->prev)
		penultimate_node->prev->next = last_node;
	else
	{
		*lst = last_node;
		penultimate_node->prev = NULL;
	}
	last_node->next = penultimate_node;
	penultimate_node->next = NULL;
// adjust prev pointers
	last_node->prev = penultimate_node->prev;
	penultimate_node->prev = last_node;
}

//Pushes the top element of stack "src" to stack "dest"
void	push(t_stack **src, t_stack **dest)
{
	t_stack	*dest_last;
	t_stack	*pushed_node;

	if (!*src)
		return ;
	pushed_node = ft_lstlast(*src);
	if (!*dest)
		*dest = pushed_node;
	else
	{
		dest_last = ft_lstlast(*dest);
		dest_last->next = pushed_node;
	}
	pushed_node->next = NULL;
	pushed_node->prev->next = NULL;
}

/* void	rotate(t_stack **lst)
{

} */
