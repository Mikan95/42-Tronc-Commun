/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameechan <ameechan@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 13:33:29 by ameechan          #+#    #+#             */
/*   Updated: 2024/09/16 13:33:31 by ameechan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//Counts and returns the height of a **char
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
int	valid_char(t_map *node, char c)
{
	if (c == '0' || c == '1' || c == 'C' || c == 'E' || c == 'P')
		return (1);
	else
		free_elements(node, ERR_004);
	return (0);
}

void	store_exit(t_map *node, int i, int j)
{
	t_pos	*exit;

	exit = malloc(sizeof(t_pos));
	if (!exit)
		free_elements(node, ERR_114);
	exit->y = i;
	exit->x = j;
	node->exit = exit;
}
