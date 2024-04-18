/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameechan <ameechan@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 12:44:32 by ameechan          #+#    #+#             */
/*   Updated: 2024/04/18 14:15:59 by ameechan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//iterates through a linked list and checks if it is sorted in ascending order
int	is_sorted(t_stack *lst)
{
	t_stack	*current;

	current = lst;
	if (!lst || ft_lstsize(lst) < 2)
		return (1);
	while (current->value < current->next->value)
		current = current->next;
	if (!current)
		return (1);
	else
		return (0);
}

//swaps the top two elements of stack "lst"
void	swap(t_stack **lst)
{
	t_stack	*old_first;
	t_stack	*new_first;

	old_first = *lst;
	new_first = old_first->next;
// adjust next pointers
	old_first->next = new_first->next;
	new_first->next->prev = old_first;
	new_first->next = old_first;
// adjust prev pointers
	new_first->prev = NULL;
	old_first->prev = new_first;
// adjust head_node
	*lst = new_first;
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

void	rotate(t_stack **lst)
{
	t_stack	*old_first;
	t_stack	*old_last;

	old_first = *lst;
	old_last = ft_lstlast(*lst);
	*lst = old_first->next;
	old_first->next->prev = NULL;
	old_first->next = NULL;
	old_first->prev = old_last;
	old_last->next = old_first;
}

void		reverse_rotate(t_stack **lst)
{
	t_stack	*old_first;
	t_stack	*old_last;

	old_first = *lst;
	old_last = ft_lstlast(*lst);
	*lst = old_last;
	old_last->next = old_first;
	old_first->prev = old_last;
	old_last->prev->next = NULL;
	old_last->prev = NULL;
}
