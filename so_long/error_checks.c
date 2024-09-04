/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_checks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameechan <ameechan@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 17:22:30 by ameechan          #+#    #+#             */
/*   Updated: 2024/09/04 17:22:42 by ameechan         ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
[1]	Checks if the command line arguments are valid,
	if the file is a .ber file and if the file can be opened.

	Returns: the file descriptor of the opened file.
*/
int	arg_check(int argc, char **argv)
{
	int	fd;
	int	i;

	if (argc != 2)
	{
		ft_printf("Error\nUsage: %s <map_file>\n", argv[0]);
		exit(1);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		perror("Error\nCould not open file\n");
		exit(1);
	}
	i = 0;
	while (argv[1][i] && !(argv[1][i] == '.' && argv[1][i + 1] == 'b' &&
		argv[1][i + 2] == 'e' && argv[1][i + 3] == 'r'))
		i++;
	if (!argv[1][i])
	{
		ft_printf("Error\nFile %s is not a .ber file\n", argv[1]);
		exit(1);
	}
	return (fd);
}

/*
[2]	Checks that all lines are the same length.
	If the map is square/rectangular, returns the length of the first line.
	If not, prints out an error message.
*/
int	line_len_check(char **map)
{
	int		i;
	int		len;
	char	**temp;

	i = 0;
	temp = map;
	len = ft_mystrlen(temp[i]);
	while (temp[i])
	{
		if (ft_mystrlen(temp[i]) == len)
			i++;
		else
			ft_perror("Error\nMap is not rectangular or square");
	}
	return (len);
}

/*
[3]	Checks that only valid chars are used in the map file.
	also counts occurences of 'P', 'E', and 'C'
*/
void	char_check(char **map, t_map *node)
{
	int	i;
	int	j;

	node->p_total = 0;
	node->e_total = 0;
	node->c_total = 0;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j] && valid_char(map[i][j]))
		{
			if (map[i][j] == 'P')
				node->p_total++;
			else if (map[i][j] == 'E')
				node->e_total++;
			else if (map[i][j] == 'C')
				node->c_total++;
			j++;
		}
		i++;
	}
	check_pec(node);
}

/*
Checks that P E & C are valid
Prints out an error message and exits the program if invalid
*/
void	check_pec(t_map *node)
{
	if (node->p_total != 1)
		ft_perror("Error\nP must equal 1\n");
	if (node->e_total != 1)
		ft_perror("Error\nE must equal 1\n");
	if (node->c_total < 1)
		ft_perror("Error\nC must be > 0\n");
}

/*
Checks that the first and last line of the map are all '1' (walls)
Checks that both the first and last characters of each line between
the top and bottom of the map are '1' (walls)
*/
void	check_borders(char **map, int map_height, int map_width)
{
	int	i;

	i = 0;
	while (i < map_width)
	{
		if (map[0][i] == '1' && map[map_height - 1][i] == '1')
			i++;
		else
			ft_perror("Error\nMap's top or bottom borders are not valid");
	}
	i = 1;
	while (i < map_height)
	{
		if (map[i][0] == '1' && map[i][map_width - 1] == '1')
			i++;
		else
			ft_perror("Error\nMap's side borders are not valid");
	}
}
