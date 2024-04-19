/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameechan <ameechan@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 12:43:41 by ameechan          #+#    #+#             */
/*   Updated: 2024/04/19 19:03:41 by ameechan         ###   ########.fr       */
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
/*		else
			sort_stacks(&a, &b); */

//########## T E S T S ###########
//	test_push(&a, &b);//TEST
//	test_swap(&a, &b);//TEST
//	test_rotate(&a, &b);//TEST
//	test_reverse_rotate(&a, &b);//TEST
//################################
	}
	ft_freelist(a);
//	test_free(&a);
	return (0);
}

void	sort_three(t_stack **lst)
{
	t_stack	*smallest;
	t_stack	*biggest;
	t_stack	*head_node;

	find_minmax(*lst, smallest, biggest);
	head_node = *lst;
	if (smallest == head_node && biggest == head_node->next)
	{
		reverse_rotate(lst);
		swap(lst);
	}
	else if (smallest == head_node->next && biggest != head_node)
		swap(lst);
	else if (smallest == head_node->next && biggest == head_node)
		rotate(lst);
	else if (biggest == head_node && smallest != head_node->next)
	{
		swap(lst);
		reverse_rotate(lst);
	}
	else
		reverse_rotate(lst);
}

void	find_minmax(t_stack *lst, t_stack *min, t_stack *max)
{
	t_stack	*first;
	t_stack	*second;
	t_stack	*third;

	first = lst;
	second = lst->next;
	third = second->next;
	min = first;
	if (first->value < second->value && second->value < third->value)
		max = third;
	if (first->value < second->value && second->value > third->value)
		max = second;
	if (first->value > second->value && second->value > third->value)
	{
		min = third;
		max = first;
	}
}

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
