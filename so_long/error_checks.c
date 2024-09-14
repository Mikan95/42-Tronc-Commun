/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_checks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameechan <ameechan@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 17:37:10 by ameechan          #+#    #+#             */
/*   Updated: 2024/09/14 14:54:10 by ameechan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
[1]	Checks if the command line arguments are valid,
	if the file is a .ber file and if the file can be opened.

	Returns: the file descriptor of the opened file.
*/
void	arg_check(int argc, char **argv)
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
}

/*
[2]	Checks that all lines are the same length as the first line (node->width)
	If not, prints out an error message.
*/
void	line_len_check(t_map *node)
{
	int		i;
	int		len;
	char	**temp;

	i = 0;
	temp = node->map;
	len = node->width;
	while (temp[i])
	{
		if (ft_mystrlen(temp[i]) == len)
			i++;
		else
			free_elements(node, "Error\nMap is not rectangular or square");
	}
}

/*
[3]	Checks that only valid chars are used in the map file.
	also counts occurences of 'P', 'E', and 'C'
*/
void	char_check(t_map *node)
{
	int	i;
	int	j;

	i = 0;
	while (node->map[i])
	{
		j = 0;
		while (node->map[i][j] &&
				valid_char(node->map[i][j]))
		{
			if (node->map[i][j] == 'P')
				node->p_total++;
			else if (node->map[i][j] == 'E')
			{
				store_exit(node, i, j);
				node->e_total++;
			}
			else if (node->map[i][j] == 'C')
				node->c_total++;
			j++;
		}
		i++;
	}
	check_pec(node);
}

void	store_exit(t_map *node, int i, int j)
{
	t_pos	*exit;

	exit = malloc(sizeof(t_pos));
	if (!exit)
		free_elements(node, "Error\nMemory allocation failure\n");
	exit->y = i;
	exit->x = j;
	node->exit = exit;
}

/*
Checks that P E & C are valid
Prints out an error message and exits the program if invalid
*/
void	check_pec(t_map *node)
{
	if (node->p_total != 1)
		free_elements(node, "Error\nP must equal 1\n");
	if (node->e_total != 1)
		free_elements(node, "Error\nE must equal 1\n");
	if (node->c_total < 1)
		free_elements(node, "Error\nC must be > 0\n");
}

/*
Checks that the first and last line of the map are all '1' (walls)
Checks that both the first and last characters of each line between
the top and bottom of the map are '1' (walls)
*/
void	check_borders(t_map *node, int map_height, int map_width)
{
	int	i;

	i = 0;
	while (i < map_width)
	{
		if (node->map[0][i] == '1' &&
				node->map[map_height - 1][i] == '1')
			i++;
		else
			free_elements(node, "Error\nMap's top or bottom borders are not valid");
	}
	i = 1;
	while (i < map_height)
	{
		if (node->map[i][0] == '1' &&
				node->map[i][map_width - 1] == '1')
			i++;
		else
			free_elements(node, "Error\nMap's side borders are not valid");
	}
}
