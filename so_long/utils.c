/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameechan <ameechan@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 16:23:37 by ameechan          #+#    #+#             */
/*   Updated: 2024/09/09 16:28:08 by ameechan         ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//Counts and returns the size of a **char
int	array_size(char **array)
{
	int	size;

	size = 0;
	while (array[size])
		size++;
	return (size);
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

void	ft_perror(char *errmsg)
{
	ft_printf("%s\n", errmsg);
	exit (1);
}
