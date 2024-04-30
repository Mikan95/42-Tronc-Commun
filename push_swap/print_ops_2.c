/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ops_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameechan <ameechan@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 14:35:36 by ameechan          #+#    #+#             */
/*   Updated: 2024/04/30 14:35:48 by ameechan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stack **lst)
{
	reverse_rotate(lst);
	ft_printf("rra\n");
}

void	rrb(t_stack **lst)
{
	reverse_rotate(lst);
	ft_printf("rrb\n");
}
