/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameechan <ameechan@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 12:43:41 by ameechan          #+#    #+#             */
/*   Updated: 2024/04/06 17:20:42 by ameechan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*a;
//	t_stack	*b;
	a = NULL;
//	b = NULL;
//	int		i = 0;

	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (-1);


//	uses ft_split to put each argument into argv
	else if (argc == 2)
		argv = ft_split(argv[1], ' ');
//	ft_printf("list of argv:\n");
//	while(argv[i])
//		ft_printf("%s\n", argv[i++]);


// intialise stack and convert str from argv[] to long int using ft_atol
	ft_printf("initialising stack..\n");
	init_stack_a(&a, argv);
	ft_printf("list size: %d", ft_lstsize(a));
//	ft_printf("Below is stack a printed out:\n");
//	ft_printf("%d\n", a->value);
//	ft_printf("%d\n", a->prev->value);
/*	if(!stack_sorted(a))
	{
		if (ft_lstsize(a) == 2)
			sa(&a, false);
		else if (ft_lstsize(a) == 3)
			sort_three(&a);
		else
			sort_stacks(&a, &b);
	}
	free_stack(&a); */
	return (0);
}
