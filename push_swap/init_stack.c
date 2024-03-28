/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameechan <ameechan@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 15:44:21 by ameechan          #+#    #+#             */
/*   Updated: 2024/03/28 15:57:17 by ameechan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_stack_a(t_stack **stack_a, char **argv)
{
	int			i;
	long int	res;
	t_stack		*new_node;

	i = 0;
	new_node = malloc(sizeof(t_stack));
	if (!new_node)
		return ;
	while (argv[i])
	{
		res = ft_atol(argv[i]);
		if (res == NULL)
			return ;
		new_node->value = res;
		ft_lstadd_back(stack_a, new_node);
		i++;
	}
}
