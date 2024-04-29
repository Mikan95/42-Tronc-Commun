/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ops.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameechan <ameechan@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 22:09:42 by ameechan          #+#    #+#             */
/*   Updated: 2024/04/29 22:09:42 by ameechan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stack **src, t_stack **dest)
{
	push(src, dest);
	ft_printf("pa\n");
}

void	pb(t_stack **src, t_stack **dest)
{
	push(src, dest);
	ft_printf("pb\n");
}

void	sa(t_stack **lst)
{
	swap(lst);
	ft_printf("sa\n");
}

void	sb(t_stack **lst)
{
	swap(lst);
	ft_printf("sb\n");
}

void	ra(t_stack **lst)
{
	rotate(lst);
	ft_printf("ra\n");
}

void	rb(t_stack **lst)
{
	rotate(lst);
	ft_printf("rb\n");
}

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
