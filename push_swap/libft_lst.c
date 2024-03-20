/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_lst.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameechan <ameechan@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 14:48:11 by ameechan          #+#    #+#             */
/*   Updated: 2024/03/20 17:09:40 by ameechan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_lstlast(t_stack *lst)
{
	t_stack	*current;

	if (lst == NULL)
		return (NULL);
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
		*lst = new;
		return ;
	}
	last = ft_lstlast(*lst);
	last->next = new;
	new->next = NULL;
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


