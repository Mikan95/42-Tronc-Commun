/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameechan <ameechan@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 14:44:13 by ameechan          #+#    #+#             */
/*   Updated: 2024/08/08 15:28:54 by ameechan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_check(int fd, char *map_path)
{
	char	**map;
	int		i;
	int		j;
	// int		player_count;
	// int		exit_count;
	// int		collectable_count;

	map = NULL;
	map_malloc(fd, &map, map_path);
	map_fill(fd, map);
	i = 0;
	while (map[i] && same_line_length(map[i], i))
	{
		j = 0;
		while (map[i][j] && valid_char(map[i][j]))
			j++;
		ft_printf("Line %d is valid\n", i);
		i++;
	}
}

/*
allocates memory for the map array,terminates the array with a NULL pointer
*/
void	map_malloc(int fd, char ***map, char *map_path)
{
	int	line_count;

	ft_printf("Map malloc:\n");
	line_count = count_lines(&fd, map_path);
	*map = malloc(sizeof(char *) * (line_count + 1));
	if (!(*map))
	{
		perror("Error\nproblem allocating memory for map\n");
		exit(1);
	}
	ft_printf("Map malloced\n");
	(*map)[line_count] = NULL;
	ft_printf("last Map slot  malloced with NULL pointer\n");
	close(fd);
	fd = open(map_path, O_RDONLY);
}

/*
Stores contents of the map file in the map array line by line.
closes map file once done.
*/
void	map_fill(int fd, char **map)
{
	int		i;
	char	*line;

	i = 0;
	while (map[i])
	{
		line = get_next_line(fd);
		if (!line)
		{
			perror("Error\nproblem getting next line from map");
			exit(1);
		}
		map[i] = ft_strdup(line);
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
