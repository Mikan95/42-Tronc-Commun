/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameechan <ameechan@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 12:43:41 by ameechan          #+#    #+#             */
/*   Updated: 2024/04/15 15:32:18 by ameechan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*temp; //delete later
	t_stack	*b;
	a = NULL;
	b = NULL;

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
	temp = a;
	while(temp)
	{
		printf("%ld\n", temp->value);
		temp = temp->next;
	}

	if(!is_sorted(a))
	{
		temp = a;
		 if (ft_lstsize(a) == 2)
		 {
			swap(&a);
			printf("AFTER SWAP\nStack A:\n");
			while(temp)//printing contents of Stack A
			{
				printf("%ld\n", temp->value);
				temp = temp->next;
			}
		 }
		else if (ft_lstsize(a) == 3)
		{
			push(&a, &b);
			printf("AFTER PUSH\nStack A:\n");
			while(temp)// printing contents of Stack A
			{
				printf("%ld\n", temp->value);
				temp = temp->next;
			}
			temp = b;
			printf("Stack B:\n");
			printf("%ld\n", temp->value);
		}
//			sort_three(&a);
//		else
//			sort_stacks(&a, &b); */
	}
	ft_freelist(a);
	printf("AFTER FREE\n");
	while(temp)
	{
		printf("%ld\n", temp->value);
		temp = temp->next;
	}
	return (0);
}
