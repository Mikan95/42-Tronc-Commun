/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameechan <ameechan@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 13:18:38 by ameechan          #+#    #+#             */
/*   Updated: 2024/09/16 13:19:27 by ameechan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
searches all accessible paths from the player start position
*/
void	bfs(char **visited, t_map *node, t_pos start)
{
	if (start.y < 0 || start.y >= node->height || start.x < 0
		|| start.x >= node->width)
		return ;
	if (visited[start.y][start.x] == 'v' || visited[start.y][start.x] == '1')
		return ;
	visited[start.y][start.x] = 'v';
	if (node->map[start.y][start.x] == 'C')
		node->c_bfs++;
	if (node->map[start.y][start.x] == 'E')
		node->e_bfs++;
	bfs(visited, node, (t_pos){start.y + 1, start.x});
	bfs(visited, node, (t_pos){start.y - 1, start.x});
	bfs(visited, node, (t_pos){start.y, start.x - 1});
	bfs(visited, node, (t_pos){start.y, start.x + 1});
}

/*
Checks if a position is within the boundaries of the map
then checks if the current position is a wall or has already been visited
returns 1 if valid position and 0 if not
*/
int	valid_pos(int row, int column, t_map *node, char **map_copy)
{
	int		valid;
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
