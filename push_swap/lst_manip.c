/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_manip.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameechan <ameechan@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 14:48:11 by ameechan          #+#    #+#             */
/*   Updated: 2024/04/12 16:38:30 by ameechan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// finds and returns the last node of a linked list
t_stack	*ft_lstlast(t_stack *lst)
{
	t_stack	*current;

	current = lst;
	while (current->next && current->next != lst)
		current = current->next;
	return (current);
}

//adds a new node to the end of a circular linked list
//last->next is always set to *lst ( pointer to head node)
void	ft_lstadd_back(t_stack **lst, long int res)
{
	t_stack	*last;
	t_stack	*new_node;

	new_node = malloc(sizeof(t_stack));
	if (!new_node)
		return ;
	new_node->value = res;
	if (!*lst)
	{
//		printf("initialising stack a for first time..\n");
		*lst = new_node;
		new_node->next = NULL;
		new_node->prev = NULL;
//		printf("First value: %ld\n", new_node->value);
//		printf("last after first value = %ld\n\n", ft_lstlast(*lst)->value);
		return ;
	}
	last = ft_lstlast(*lst);
	last->next = new_node;
	new_node->prev = last;
	new_node->next = *lst;
//	printf("Last value: %ld\n", last->value);
//	printf("New value: %ld\n", new_node->value);
}

//returns the number of nodes in a linked list
int	ft_lstsize(t_stack *lst)
{
	t_stack	*temp;
	t_stack *start;
	int		i;;

	start = NULL;
	i = 0;
	temp = lst;
	while (temp != start)
	{
		start = lst;
		temp = temp->next;
		i++;
	}
	return (i);
}

//frees each node of a linked list
void	ft_freelist(t_stack *stack_a)
{
	t_stack	*temp;
	t_stack	*start;

	start = NULL;
	temp = stack_a;
	while (temp != start)
	{
		start = stack_a;
		temp = temp->next;
		free(temp);
	}
}
