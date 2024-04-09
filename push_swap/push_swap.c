/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameechan <ameechan@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 12:43:41 by ameechan          #+#    #+#             */
/*   Updated: 2024/04/09 01:44:37 by ameechan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*print;
	int		loop;
//	t_stack	*b;
	a = NULL;
	print = NULL;
//	b = NULL;
//	int		i = 0;

	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (-1);

//	uses ft_split to put each argument into argv
	else if (argc == 2)
		argv = ft_split(argv[1], ' ');
	else
		argv = &argv[1];

//intialises stack, checks for errors, and converts elements from str to long int
	init_stack_a(&a, argv);
	ft_printf("list size: %d\n", ft_lstsize(a));
	ft_printf("Elements in Stack_a:\n");
	print = a;
	loop = -1;
	while(print->next && loop < 1)
	{
		if (print == a)
		{
			loop++;
			if (loop > 0)
				break;
		}
		printf("%ld\n", print->value);
		print = print->next;
	}

/* 	if(!stack_sorted(a))
	{
		if (ft_lstsize(a) == 2)
			sa(&a, false);
		else if (ft_lstsize(a) == 3)
			sort_three(&a);
		else
			sort_stacks(&a, &b);
	} */
	ft_freelist(a);
	return (0);
}

/*
##############################################################
insert after initialising stack to print all "value" of stack
##############################################################
	ft_printf("list size: %d\n", ft_lstsize(a));
	ft_printf("Elements in Stack_a:\n");
	while(a)
	{
		printf("%ld\n", a->value);
		a = a->next;
	}
*/
