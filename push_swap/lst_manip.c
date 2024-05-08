/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_manip.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameechan <ameechan@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 14:48:11 by ameechan          #+#    #+#             */
/*   Updated: 2024/05/02 14:19:38 by ameechan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// returns the number of nodes in a linked list
int	ft_lstsize(t_stack *lst)
{
	t_stack	*temp;
	int		i;

	i = 0;
	temp = lst;
	while (temp)
	{
		temp = temp->next;
		i++;
	}
	return (i);
}

// finds and returns the last node of a linked list
t_stack	*ft_lstlast(t_stack *lst)
{
	t_stack	*current;

	current = lst;
	while (current->next)
		current = current->next;
	return (current);
}

// adds a new node to the end of a single linked list
void	ft_lstadd_back(t_stack **lst, long int res)
{
	t_stack	*last;
	t_stack	*new_node;

	new_node = malloc(sizeof(t_stack));
	if (!new_node)
		return ;
	new_node->next = NULL;
	new_node->value = res;
	if (!*lst)
	{
		*lst = new_node;
		new_node->prev = NULL;
		return ;
	}
	else
	{
		last = ft_lstlast(*lst);
		last->next = new_node;
		new_node->prev = last;
	}
}

//brings smallest element of stack_a to the top
void	min_to_top(t_stack **a)
{
	t_stack	*min;

	min = find_min(*a);
	if (min->above_median)
	{
		while (*a != min)
			ra(a);
	}
	else
	{
		while (*a != min)
			rra(a);
	}
}

//frees each node of a linked list
void	ft_freelist(t_stack *stack_a)
{
	t_stack	*temp;
	t_stack	*first;

	first = stack_a;
	while (first)
	{
		temp = first;
		first = first->next;
		free(temp);
	}
	free(first);
}
