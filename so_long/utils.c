/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameechan <ameechan@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 21:17:42 by ameechan          #+#    #+#             */
/*   Updated: 2024/08/12 21:31:26 by ameechan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
Receives the number of occurences of P, E and C and checks they are valid
Prints out an error message and exits the program if invalid
*/
void	check_pec(int P_count, int E_count, int C_count)
{
	if (P_count != 1)
	{
		ft_printf("Error\nP must equal 1\nCurrent P = %d", P_count);
		exit (1);
	}
	if (E_count != 1)
	{
		ft_printf("Error\nE must equal 1\nCurrent E = %d", E_count);
		exit (1);
	}
	if (C_count < 1)
	{
		ft_printf("Error\nC must be > 0\nCurrent C = %d", C_count);
		exit (1);
	}
}

//Counts and returns the length of a string
int	ft_mystrlen(char *str)
{
	int	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

/*
Checks that only valid characters are used in the map file
Exits the program with an error message if an invalid character is found
*/
int	valid_char(char c)
{
	if (c == '0' || c == '1' || c == 'C' || c == 'E' || c == 'P')
		return (1);
	else
	{
		perror("Error\nInvalid character used in map file");
		exit(1);
	}
	return (0);
}
