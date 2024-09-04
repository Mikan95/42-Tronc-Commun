/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameechan <ameechan@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 15:58:01 by ameechan          #+#    #+#             */
/*   Updated: 2024/09/04 16:00:24 by ameechan         ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#define MAX_ROWS 100
#define MAX_COLS 100

void	bfs(char **map_copy, t_map *node)
{
	int		front;
	int		rear;
	t_pos	queue[MAX_ROWS * MAX_COLS];
	t_pos	current;

	front = 0;
	rear = 0;
	queue[rear].column = node->start->column;
	queue[rear].row = node->start->row;
	rear++;
	map_copy[node->start->row][node->start->column] = 'v';
	if (!valid_pos(1, 5, node, map_copy))
		ft_perror("Error\nInvalid position or already visited\n");
	while (front < rear)
	{
		current = queue[front];
		front = rear;
		// move_row(current.row, current.column, width, height, );
		ft_printf("current: %d:%d\n", current.row, current.column);
	}
}

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
