/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameechan <ameechan@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 13:59:24 by ameechan          #+#    #+#             */
/*   Updated: 2024/09/16 13:59:41 by ameechan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
checks and frees all elements accordingly
before printing an error message and exiting the program
*/
void	free_elements(t_map *node, char *errmsg)
{
	if (!node)
		return ;
	if (node->map)
		free_map(node->map);
	if (node->visited)
		free_map(node->visited);
	if (node->map_str)
		free(node->map_str);
	if (node->exit)
		free(node->exit);
	if (node->start)
		free(node->start);
	free(node);
	ft_printf("%s", errmsg);
	exit (1);
}

/*
frees the contents of a 2d array
*/
void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}
