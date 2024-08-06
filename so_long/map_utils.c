/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameechan <ameechan@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 14:44:13 by ameechan          #+#    #+#             */
/*   Updated: 2024/08/06 17:32:49 by ameechan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_check(int fd, char *map_path)
{
	char	**map;

	map = NULL;
	map_malloc(fd, &map, map_path);
	map_fill(fd, map);
}

/*
allocates memory for the map array,terminates the array with a NULL pointer
*/
void	map_malloc(int fd, char ***map, char *map_path)
{
	int	line_count;

	ft_printf("Map malloc:\n");
	line_count = count_lines(&fd, map_path);
	map = malloc(sizeof(char *) * (line_count + 1));
	if (!map)
	{
		perror("Error\nproblem allocating memory for map\n");
		exit(1);
	}
	ft_printf("Map malloced\n");
	map[line_count] = NULL;
	ft_printf("Map malloced with NULL pointer\n");
	close(fd);
	fd = open(map_path, O_RDONLY);
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

void	map_fill(int fd, char **map)
{
	int		i;
	char	*line;

	i = 0;
	ft_printf("Map fill:\n");
	line = get_next_line(fd);
	printf("line: %s\n", line);
	map[i] = malloc(ft_strlen(line) + 1);
	if (!map[i])
	{
		perror("Error\nproblem allocating memory for map\n");
		exit(1);
	}
	map[i] = line;
	printf("gnl done: %s\n", map[i]);
	// printf("attempting strlcpy\n");
	// map[i] = malloc(ft_strlen(line) + 1);
	// ft_strlcpy(map[i], line, ft_strlen(line) + 1);
	// printf("strlcpy done\n");
	ft_printf("first line filled:\n");
}
