/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameechan <ameechan@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 12:43:41 by ameechan          #+#    #+#             */
/*   Updated: 2024/05/02 14:09:39 by ameechan         ###   ########.fr       */
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
	if (!is_sorted(a))
	{
		if (ft_lstsize(a) == 2)
			sa(&a);
		else if (ft_lstsize(a) == 3)
			sort_three(&a);
		else
			sort_stacks(&a, &b);
	}
	free_all(a, b, argv, argc);
	return (0);
}

//frees all allocated memory at end of process
void	free_all(t_stack *a, t_stack *b, char **argv, int argc)
{
	int	i;

	ft_freelist(a);
	ft_freelist(b);
	if (argc == 2)
	{
		i = 0;
		while (argv[i])
			free(argv[i++]);
		free (argv);
	}
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
