/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_lst.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameechan <ameechan@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 14:48:11 by ameechan          #+#    #+#             */
/*   Updated: 2024/04/06 17:22:50 by ameechan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_lstlast(t_stack *lst)
{
	t_stack	*current;

	current = lst;
	while (current->next)
		current = current->next;
	return (current);
}

void	ft_lstadd_back(t_stack **lst, t_stack *new)
{
	t_stack	*last;

	if (!new)
		return ;
	if (!*lst)
	{
		printf("initialising stack a for first time..\n");
		*lst = new;
		new->next = NULL;
		new->prev = NULL;
		printf("First value: %ld\n", new->value);
		printf("last after first value = %ld\n\n", ft_lstlast(*lst)->value);
		return ;
	}
	last = ft_lstlast(*lst);
	last->next = new;
	new->prev = last;
	new->next = NULL;
	printf("Last value: %ld\n", last->value);
	printf("New value: %ld\n", new->value);
}

int	ft_lstsize(t_stack *lst)
{
	t_stack	*temp;
	int		i;

	temp = lst;
	i = 0;
	while (temp != NULL)
	{
		i++;
		temp = temp->next;
	}
	return (i);
}


