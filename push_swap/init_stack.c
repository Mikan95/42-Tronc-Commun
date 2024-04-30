/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameechan <ameechan@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 15:44:21 by ameechan          #+#    #+#             */
/*   Updated: 2024/04/30 14:30:23 by ameechan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* initialises the stack, adding each element of argv to the end of the list,
once each str has been converted to long ints using ft_atol() */
void	init_stack_a(t_stack **stack_a, char **argv)
{
	int			i;
	long int	res;

	if (ft_error_check(argv))
	{
		ft_freelist(*stack_a);
		write (2, "Error\n", 6);
		exit (-1);
	}
	else
	{
		i = 0;
		while (argv[i])
		{
			res = ft_atol(argv[i]);
			ft_lstadd_back(stack_a, res);
			i++;
		}
	}
}

//runs through multiple checks and returns 1 if an error has been found.
int	ft_error_check(char **argv)
{
	int	i;
	int	flag;

	flag = 0;
	i = 0;
	while (argv[i])
	{
		if (ft_check_syntax(argv[i]) || ft_check_dupli(argv))
			flag = 1;
		if (flag == 1)
			return (1);
		i++;
	}
	return (0);
}

/* reads elements from an array, checks for syntax errors.
returns 1 if error is found */
int	ft_check_syntax(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i + 1] < '0' || str[i] > '9')
			return (1);
		i++;
	}
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (1);
		i++;
	}
	return (0);
}

/* checks for duplicates in an array and returns 1 if found.
also checks for integer overflow */
int	ft_check_dupli(char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (argv[i])
	{
		j = i + 1;
		while (argv[j] && (ft_atol(argv[i])) != (ft_atol(argv[j])))
			j++;
		if (argv[j] && (ft_atol(argv[i])) == (ft_atol(argv[j])))
			return (1);
		if ((ft_atol(argv[i])) < INT_MIN || (ft_atol(argv[i])) > INT_MAX)
			return (1);
		i++;
	}
	return (0);
}
