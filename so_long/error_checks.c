/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_checks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameechan <ameechan@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 12:43:33 by ameechan          #+#    #+#             */
/*   Updated: 2024/08/12 21:41:49 by ameechan         ###   ########.fr       */
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
	If not, prints out an error message.
*/
void	line_len_check(char **map)
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
		{
			perror("Error\nMap is not rectangular or square");
			exit (1);
		}
	}
}

/*
[3]	Checks that only valid chars are used in the map file.
	also counts occurences of 'P', 'E', and 'C'
		Player			= counts[0]
		Exit			= counts[1]
		Collectibles	= counts[2]
*/
void	char_check(char **map)
{
	int	i;
	int	j;
	int	counts[3];

	counts[0] = 0;
	counts[1] = 0;
	counts[2] = 0;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j] && valid_char(map[i][j]))
		{
			if (map[i][j] == 'P')
				counts[0]++;
			else if (map[i][j] == 'E')
				counts[1]++;
			else if (map[i][j] == 'C')
				counts[2]++;
			j++;
		}
		i++;
	}
	check_pec(counts[0], counts[1], counts[2]);
}

//void	wall_check()
