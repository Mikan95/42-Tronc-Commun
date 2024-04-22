/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stacks_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameechan <ameechan@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 16:46:37 by ameechan          #+#    #+#             */
/*   Updated: 2024/04/22 16:53:04 by ameechan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//sets and refreshes the index of each el;ement in a list.
//also sets whether the element is above or below the median.
void	set_index(t_stack *lst)
{
	int	i;
	int	median;

	i = 0;
	if (!lst)
		return ;
	median = ft_lstsize(lst) / 2;
	while (lst)
	{
		lst->index = i;
		if (i <= median)
			lst->above_median = true;
		else
			lst->above_median = false;
		lst = lst->next;
		i++;
	}
}
