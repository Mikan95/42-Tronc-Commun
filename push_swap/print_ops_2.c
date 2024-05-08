/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ops_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameechan <ameechan@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 17:33:09 by ameechan          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2024/05/01 17:14:23 by ameechan         ###   ########.fr       */
=======
/*   Updated: 2024/05/02 14:06:49 by ameechan         ###   ########.fr       */
>>>>>>> turnin
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// prints "rra" and reverse rotates stack_a
void	rra(t_stack **lst)
{
	reverse_rotate(lst);
	ft_printf("rra\n");
}

// prints "rrb" and reverse rotates stack_b
void	rrb(t_stack **lst)
{
	reverse_rotate(lst);
	ft_printf("rrb\n");
}
