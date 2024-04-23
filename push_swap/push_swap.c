/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameechan <ameechan@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 12:43:41 by ameechan          #+#    #+#             */
/*   Updated: 2024/04/23 19:12:51 by ameechan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	t_stack	*min;// DELETE LATER
	a = NULL;
	b = NULL;
	min = NULL;

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
	ft_printf("Elements in Stack A:\n");
	test_print_elements_lst(a, b);

	if(!is_sorted(a))
	{
		printf("sorting...\n");
		 if (ft_lstsize(a) == 2)
		 {
			swap(&a);
			printf("AFTER SWAP\n");//DELETE LATER
			test_print_elements_lst(a, b);//DELETE LATER
		 }
		else if (ft_lstsize(a) == 3)
			sort_three(&a);
 		else
			sort_stacks(&a, &b);

//########## T E S T S ###########
//	test_push(&a, &b);//TEST
//	test_reverse_rotate(&a, &b);//TEST
//	test_swap(&a, &b);//TEST
//	test_rotate(&a, &b);//TEST
//	test_print_elements_lst(a, b);//TEST FOR SORT_THREE
//################################
	}
	else								 //delete later
		printf("LIST ALREADY SORTED!\n");//delete later
	ft_freelist(a);
//	test_free(&a);
	return (0);
}

void	sort_three(t_stack **lst)
{
	t_stack	*biggest;

	printf("List sorted:\n");
}

void	find_minmax(t_stack *lst, t_stack **min, t_stack **max)
{
	t_stack	*first;
	t_stack	*second;
	t_stack	*third;
	t_stack	*print_min;//delete
	t_stack	*print_max;//delete

	printf("Finding min and max\n");
	first = lst;
	second = lst->next;
	third = second->next;
	if (first->value < second->value && first->value < third->value)
		*min = first;
	else if (second->value < first->value && second->value < third->value)
		*min = second;
	else if (third->value < first->value && third->value < second->value)
		*min = third;
	if (first->value > second->value && first->value > third->value)
		*max = first;
	else if (second->value > first->value && second->value > third->value)
		*max = second;
	else
		*max = third;
	print_min = *min;
	print_max = *max;
	printf("Min is: %ld\nMax is: %ld\n", print_min->value, print_max->value);
}

//finds min in a given stack and sets pointer min
void	find_min(t_stack *lst, t_stack *min)
{
	t_stack	*current;

	current = lst;
	min = current;
	while (current->next)
	{
		if (current->value < min->value)
			min = current;
		current = current->next;
	}
//	printf("Min value: %ld\n", min->value);
}

//finds max in a given stack and sets pointer max
void	find_max(t_stack *lst, t_stack *max)
{
	t_stack	*current;

	current = lst;
	max = current;
	while (current->next)
	{
		if (current->value > max->value)
			max = current;
		current = current->next;
	}
//	printf("Max value: %ld\n", max->value);
}

//#################################################//
//################ TEST FUNCTIONS #################//
//#################################################//

void	test_print_elements_lst(t_stack *a, t_stack *b)
{
	t_stack	*temp;

	ft_printf("Elements in Stack A:\n");
	temp = a;
	while(temp)//printing elements of Stack A
	{
		printf("%ld\n", temp->value);
		temp = temp->next;
	}
	ft_printf("Elements in Stack B:\n");
	temp = b;
	while(temp)//printing elements of Stack B
	{
		printf("%ld\n", temp->value);
		temp = temp->next;
	}
}

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
}
