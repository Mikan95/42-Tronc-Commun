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

// prints "pa" and pushes top node from stack_b to stack_a
void	pa(t_stack **src, t_stack **dest)
{
	push(src, dest);
	ft_printf("pa\n");
}

// prints "pb" and pushes top node from stack_a to stack_b
void	pb(t_stack **src, t_stack **dest)
{
	push(src, dest);
	ft_printf("pb\n");
}

// prints "sa" and swaps first two elements of stack_a
void	sa(t_stack **lst)
{
	swap(lst);
	ft_printf("sa\n");
}

// prints "ra" and rotates stack_a
void	ra(t_stack **lst)
{
	rotate(lst);
	ft_printf("ra\n");
}

//prints "rb" and rotates stack_b
void	rb(t_stack **lst)
{
	rotate(lst);
	ft_printf("rb\n");
}
