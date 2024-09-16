/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameechan <ameechan@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 13:22:04 by ameechan          #+#    #+#             */
/*   Updated: 2024/09/16 13:22:27 by ameechan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* static void	print_array(char **array)
{
	int	i = 0;

	while (array[i])
	{
	ft_printf("%s\n", array[i]);
	i++;
	}
	ft_printf("\n");
} */
/*
Checks if map contents are valid
ie: allowed chars only (0, 1, P, E, C)
	only 1 Exit and Player start position
	at least 1 collectible
	rectangular map
	surrounded by walls
	must have valid path
*/
void	map_check(t_map *node)
{
	init_map(node);
	line_len_check(node);
	char_check(node);
	check_borders(node, node->height, node->width);
	find_start(node->map, node);
	node->player = node->start;
	bfs(node->visited, node, (*node->start));
	if (node->c_total != node->c_bfs
		|| node->e_total != node->e_bfs)
		free_elements(node, ERR_008);
	node->map[node->exit->y][node->exit->x] = '1';
}

/*
reads the map file and stores it in the map array and visited array
also stores the map height and width in the t_map *node
*/
void	init_map(t_map *node)
{
	ssize_t	bytes_read;

	node->fd = open(node->file_path, O_RDONLY);
	if (node->fd < 0)
		free_elements(node, ERR_101);
	node->map_str = malloc(sizeof(char) * 10240);
	if (!node->map_str)
		free_elements(node, ERR_112);
	bytes_read = read(node->fd, node->map_str, 10240);
	if (bytes_read <= 0)
		free_elements(node, ERR_102);
	node->map_str[bytes_read] = '\0';
	node->map = ft_split(node->map_str, '\n');
	node->visited = ft_split(node->map_str, '\n');
	if (!node->map || !node->visited)
		free_elements(node, ERR_103);
	node->height = array_size(node->map);
	node->width = ft_mystrlen(node->map[0]);
}

/*
Reads 1024 bytes at a time, then counts and returns
the number of lines in the map file.
Also resets the file descriptor to the beginning of the file.
*/
int	count_lines(int *fd, char *map_path)
{
	int		count;
	char	buf[BUFFER_SIZE];
	ssize_t	bytes_read;
	int		i;

	count = 0;
	bytes_read = read(*fd, buf, BUFFER_SIZE);
	if (bytes_read <= 0)
		return (-2);
	while (bytes_read > 0)
	{
		i = 0;
		while (i < bytes_read)
		{
			if (buf[i] == '\n')
				count++;
			i++;
		}
		bytes_read = read(*fd, buf, BUFFER_SIZE);
	}
	close(*fd);
	*fd = open(map_path, O_RDONLY);
	return (count);
}

/*
Finds the position of `P` in `map` and stores its coordinates
in `start_pos` struct
*/
void	find_start(char **map, t_map *node)
{
	int		i;
	int		j;
	t_pos	*start;

	start = malloc(sizeof(t_pos));
	if (!start)
		free_elements(node, ERR_113);
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
			{
				start->y = i;
				start->x = j;
			}
			j++;
		}
		i++;
	}
	node->start = start;
}
