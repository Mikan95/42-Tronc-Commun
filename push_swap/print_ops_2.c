/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ops_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameechan <ameechan@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 17:33:09 by ameechan          #+#    #+#             */
/*   Updated: 2024/05/01 15:15:23 by ameechan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stack **lst)
{
	reverse_rotate(lst);
//	ft_printf("rra\n");
}

void	rrb(t_stack **lst)
{
	reverse_rotate(lst);
//	ft_printf("rrb\n");
}
