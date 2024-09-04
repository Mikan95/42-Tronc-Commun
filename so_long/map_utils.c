/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameechan <ameechan@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 17:37:59 by ameechan          #+#    #+#             */
/*   Updated: 2024/09/04 17:49:30 by ameechan         ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	print_array(char **array)
{
	int	i = 0;

	while (array[i])
	{
	ft_printf("%s\n", array[i]);
	i++;
	}
	ft_printf("\n");
}

static void	bfs(char **visited, t_map *node, t_pos start)
{
	if (start.x < 0 || start.x >= node->width || start.y < 0
		|| start.y >= node->height)
		return ;
	if (visited[start.y][start.x] == 'v'
		|| node->map[start.y][start.x] == '1')
		return ;
	print_array(visited);
	visited[start.y][start.x] = 'v';
	if (node->map[start.y][start.x] == 'C')
		node->c_bfs++;
	bfs(visited, node, (t_pos){start.x + 1, start.y});
	bfs(visited, node, (t_pos){start.x - 1, start.y});
	bfs(visited, node, (t_pos){start.x, start.y + 1});
	bfs(visited, node, (t_pos){start.x, start.y - 1});
}

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
/* 	ft_printf("before bfs visited:\n");
	print_array(node->visited); */
	bfs(node->visited, node, *(node->start));
	ft_printf("\n\nintial map:\n");
	print_array(node->map);
	ft_printf("\nafter bfs:\n");
	print_array(node->visited);
	if (node->c_bfs == node->c_total)
		ft_printf("congrats! map is valid!\n");
	else
		ft_perror("Error\nMap has unreachable collectibles\n");
	free_map(map);
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
