/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameechan <ameechan@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 12:43:41 by ameechan          #+#    #+#             */
/*   Updated: 2024/03/02 13:46:49 by ameechan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	invalid_char_checker(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-')
		i++;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			i++;
		else
			return (0);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	int	i;
	int	test_i;
	unsigned int	test;

	if (argc < 2)
		exit(-1);
	i = 1;
	while (i < (argc - 1) && invalid_char_checker(argv[i]) == 1)
		i++;
	if (invalid_char_checker(argv[i]) == 0)
	{
		write(2, "Error\n", 6);
		exit (0);
	}
	test_i = 0;
	test = (unsigned int);
	ft_printf("Below is a list of your arguments:\n");
	while (test_i < argc)
		ft_printf("%s\n", argv[test_i++]);
	ft_printf("normal int min is: %d\n", INT_MIN);
	ft_printf("converted int min is %u\n", (-test));
	return (0);
}
