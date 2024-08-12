/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameechan <ameechan@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 14:44:13 by ameechan          #+#    #+#             */
/*   Updated: 2024/08/12 21:34:24 by ameechan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_check(int fd, char *map_path)
{
	char	**map;
	//int	line_len;
	// int		player_count;
	// int		exit_count;
	// int		collectable_count;

	map = NULL;
	map_malloc(fd, &map, map_path);
	map_fill(fd, map);
	line_len_check(map);
	char_check(map);

}

/*
allocates memory for the map array,terminates the array with a NULL pointer
*/
void	map_malloc(int fd, char ***map, char *map_path)
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
}

/*
Stores contents of the map file in the map array line by line.
making sure to trim the \n character from GNL.
Also, closes map file once finished.
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
