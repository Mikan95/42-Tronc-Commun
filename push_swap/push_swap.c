/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameechan <ameechan@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 12:43:41 by ameechan          #+#    #+#             */
/*   Updated: 2024/05/01 17:37:10 by ameechan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	a = NULL;
	b = NULL;

	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (0);
	else if (argc == 2)
		argv = ft_split(argv[1], ' ');
	else
		argv = &argv[1];
	init_stack_a(&a, argv);
	if(!is_sorted(a))
	{
		 if (ft_lstsize(a) == 2)
			sa(&a);
		else if (ft_lstsize(a) == 3)
			sort_three(&a);
		else
			sort_stacks(&a, &b);
	}
	ft_freelist(a);
	ft_freelist(b);
	return (0);
}

//sorts a list of three nodes in ascending order
void	sort_three(t_stack **lst)
{
	t_stack	*biggest;

	biggest = find_max(*lst);
	if (biggest == *lst)
		ra(lst);
	else if (biggest == (*lst)->next)
		rra(lst);
	if ((*lst)->value > (*lst)->next->value)
		sa(lst);
}

//finds min in a given stack and returns a pointer to min
t_stack	*find_min(t_stack *lst)
{
	t_stack	*current;
	t_stack	*min;

	current = lst;
	min = current;
	while (current)
	{
		if (current->value < min->value)
			min = current;
		current = current->next;
	}
	return (min);
}

//finds max in a given stack and returns a pointer to max
t_stack	*find_max(t_stack *lst)
{
	t_stack	*current;
	t_stack	*max;

	current = lst;
	max = current;
	while (current)
	{
		if (current->value > max->value)
			max = current;
		current = current->next;
	}
	return (max);
}
//	printf("Max value: %ld\n", max->value);//										Prints max
//#################################################//
//################ TEST FUNCTIONS #################//
//#################################################//
/*
//prints all the elements of both stacks
void	test_print_elements_lst(t_stack *a, t_stack *b)
{
	t_stack	*temp;

	printf("Elements in Stack A:\n");
	temp = a;
	while(temp)
	{
		printf("%ld\n", temp->value);
		temp = temp->next;
	}
	printf("Elements in Stack B:\n");
	temp = b;
	while(temp)
	{
		printf("%ld\n", temp->value);
		temp = temp->next;
	}
} */
/*
void		test_swap(t_stack **a, t_stack **b)
{
	swap(a);
	printf("AFTER SWAP\n");
	test_print_elements_lst(*a, *b);
}

void		test_push(t_stack **a, t_stack **b)
{
	push(a, b);
	printf("AFTER PUSH\n");
	test_print_elements_lst(*a, *b);
}

void		test_rotate(t_stack **a, t_stack **b)
{
	rotate(a);
	printf("AFTER ROTATE\n");
	test_print_elements_lst(*a, *b);
}

void		test_reverse_rotate(t_stack **a, t_stack **b)
{
	reverse_rotate(a);
	printf("AFTER REVERSE ROTATE\n");
	test_print_elements_lst(*a, *b);
}

void		test_free(t_stack **lst)
{
	t_stack	*temp;

	temp = *lst;
	printf("AFTER FREE\n");
	while(temp)
	{
		printf("%ld\n", temp->value);
		temp = temp->next;
	}
} */
