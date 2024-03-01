/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameechan <ameechan@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 12:43:41 by ameechan          #+#    #+#             */
/*   Updated: 2024/03/01 17:37:10 by ameechan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	invalid_char_checker(char *arg)
{
	int	i;

	i = 0;
	if (arg[i] == '-')
		i++;
	while(arg[i])
	{
		if (arg[i] >= '0' && arg[i] <= '9')
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

	if (argc < 2)
		exit(-1);
	i = 1;
	while(i < argc)
	{
		while (invalid_char_checker(argv[i]) == 1)
			i++;
		if (invalid_char_checker(argv[i]) == 0)
		{
			write(2, "Error\n", 6);
			exit (0);
		}
	}
	test_i = 0;
	ft_printf("Below is a list of your arguments:\n");
	while (test_i < argc)
		ft_printf("%s\n", argv[test_i++]);
	return (0);
}
