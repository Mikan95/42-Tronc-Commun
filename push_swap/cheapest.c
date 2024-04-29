/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cheapest.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameechan <ameechan@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 21:44:41 by ameechan          #+#    #+#             */
/*   Updated: 2024/04/25 21:44:41 by ameechan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* calculates and sets the combined push cost of
each node in a list and their respective target_node(s) */
void	find_cheapest(t_stack *a, t_stack *b)
{
	int	len_a;
	int	len_b;

	len_a = ft_lstsize(a);
	len_b = ft_lstsize(b);
	while (a)
	{
		a->push_cost = a->index;
		if (!(a->above_median))
			a->push_cost = len_a - (a->index);
		if(a->target_node->above_median)
			a->push_cost += a->target_node->index;
		else
			a->push_cost += len_b - a->target_node->index;
//		printf("%ld's push cost: %i\n", a->value, a->push_cost);//					TEST
		a = a->next;
	}
}

/* traverses a linked list to find cheapest node
and sets (cheapest_node->cheapest = true) */
void	set_cheapest(t_stack *lst)
{
	long	current_cheapest;
	t_stack	*cheapest_node;

	if (!lst)
		return ;
	current_cheapest = LONG_MAX;
	while (lst)
	{
		if (lst->push_cost < current_cheapest)
		{
			current_cheapest = lst->push_cost;
			cheapest_node = lst;
		}
		lst = lst->next;
	}
	cheapest_node->cheapest = true;
}

//finds which node in a list is set to (current->cheapest = true)
t_stack	*get_cheapest(t_stack *lst)
{
	while (lst)
	{
		if (lst->cheapest == true)
			return (lst);
		lst = lst->next;
	}
	ft_freelist(lst);
	write (2, "Error\n", 6);
	write (1, "No cheapest node found\n", 23);
	exit (-1);
}
