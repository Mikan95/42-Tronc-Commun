/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameechan <ameechan@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 18:15:03 by ameechan          #+#    #+#             */
/*   Updated: 2024/09/05 18:15:45 by ameechan         ###   ########.ch       */
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
searches all accessible
*/
void	bfs(char **visited, t_map *node, t_pos start)
{
	if (start.y < 0 || start.y >= node->height || start.x < 0
		|| start.x >= node->width)
		return;
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
	char	**map;

	map = NULL;
	map_malloc(&map, node);
	map_fill(node);
	node->width = line_len_check(map);
	char_check(map, node);
	check_borders(map, node->height, node->width);
	bfs_prep(node);
	bfs(node->visited, node, (*node->start));
	if(node->c_total != node->c_bfs
		|| node->e_total != node->e_bfs)
	{
		free_map(map);
		ft_perror("Error\nUnreachable collectible or exit\n");
	}
}

/*
allocates memory for the map array,terminates the array with a NULL pointer
stores map and map height in t_map *node
*/
void	map_malloc(char ***map, t_map *node)
{
	int	line_count;

	line_count = count_lines(&(node->fd), node->file_path);
	*map = malloc(sizeof(char *) * (line_count + 1));
	if (!(*map))
	{
		perror("Error\nproblem allocating memory for map\n");
		exit(1);
	}
	(*map)[line_count] = NULL;
	close(node->fd);
	node->fd = open(node->file_path, O_RDONLY);
	node->map = *map;
	node->height = line_count;
}

/*
Stores contents of the map file in the map array line by line.
making sure to trim the \n character from GNL.
Also, closes map file once finished.
*/
void	map_fill(t_map *node)
{
	int		i;
	char	*line;

	i = 0;
	while (i < node->height)
	{
		line = get_next_line(node->fd);
		if (!line)
		{
			perror("Error\nproblem getting next line from map");
			exit(1);
		}
		node->map[i] = ft_strdup(line);
		node->map[i][(ft_mystrlen(node->map[i]) - 1)] = '\0';
		i++;
	}
	close(node->fd);
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
