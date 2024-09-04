/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameechan <ameechan@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 17:10:32 by ameechan          #+#    #+#             */
/*   Updated: 2024/09/04 17:10:32 by ameechan         ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
Checks if a position is within the boundaries of the map
then checks if the current position is a wall or has already been visited
returns 1 if valid position and 0 if not
*/
int	valid_pos(int row, int column, t_map *node, char **map_copy)
{
	int	valid;
	char	current;

	valid = 0;
	current = map_copy[row][column];
	if (row >= 0 && row < node->height && column >= 0 && column < node->width)
		valid = 1;
	if (current == '1' || current == 'v')
		valid = 0;
	if (valid)
		return (1);
	else
		return (0);
}
/*
	ft_printf("queue.column: %d\n", queue[rear].column);
	ft_printf("queue.row: %d\n", queue[rear].row);
	ft_printf("Starting value: %c\n", map_copy[queue[rear].row][queue[rear].column]);
	*/
