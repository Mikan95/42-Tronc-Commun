/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameechan <ameechan@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 12:43:41 by ameechan          #+#    #+#             */
/*   Updated: 2024/04/09 20:59:03 by ameechan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*temp; //delete later
	t_stack	*start;
//	t_stack	*b;
	a = NULL;
	start = NULL;
//	b = NULL;

	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (-1);
//	uses ft_split to put each argument into argv
	else if (argc == 2)
		argv = ft_split(argv[1], ' ');
	else
		argv = &argv[1];
//intialises stack, checks for errors, and converts elements from str to long int
	init_stack_a(&a, argv);
/* 	ft_printf("list size: %d\n", ft_lstsize(a));
	ft_printf("Elements in Stack_a:\n");
	temp = a;
	while(temp != start)
	{
		start = a;
		printf("%ld\n", temp->value);
		temp = temp->next;
	} */

	if(!is_sorted(a))
	{
		 if (ft_lstsize(a) == 2)
			sa(&a);
		/*else if (ft_lstsize(a) == 3)
			sort_three(&a);
		else
			sort_stacks(&a, &b); */
	}
	ft_freelist(a);
	return (0);
}
