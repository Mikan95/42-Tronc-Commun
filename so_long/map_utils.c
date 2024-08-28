/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameechan <ameechan@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 19:24:58 by ameechan          #+#    #+#             */
/*   Updated: 2024/08/28 19:25:16 by ameechan         ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_check(int fd, char *map_path)
{
	char	**map;
	int		map_height;
	int		map_width;

	map = NULL;
	map_height = map_malloc(fd, &map, map_path);
	map_fill(fd, map, map_height);
	map_width = line_len_check(map);
	char_check(map);
	check_borders(map, map_height, map_width);
	bfs(map, map_height, map_width);
	free_map(map);
}

/*
allocates memory for the map array,terminates the array with a NULL pointer
and returns the number of lines in the map file.
*/
int	map_malloc(int fd, char ***map, char *map_path)
{
	int	line_count;

	line_count = count_lines(&fd, map_path);
	*map = malloc(sizeof(char *) * (line_count + 1));
	if (!(*map))
	{
		perror("Error\nproblem allocating memory for map\n");
		exit(1);
	}
	(*map)[line_count] = NULL;
	close(fd);
	fd = open(map_path, O_RDONLY);
	return (line_count);
}

/*
Stores contents of the map file in the map array line by line.
making sure to trim the \n character from GNL.
Also, closes map file once finished.
*/
void	map_fill(int fd, char **map, int map_height)
{
	int		i;
	char	*line;

	i = 0;
	while (i < map_height)
	{
		line = get_next_line(fd);
		if (!line)
		{
			perror("Error\nproblem getting next line from map");
			exit(1);
		}
		map[i] = ft_strdup(line);
		map[i][(ft_mystrlen(map[i]) - 1)] = '\0';
		i++;
	}
	close(fd);
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
