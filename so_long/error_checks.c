/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_checks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameechan <ameechan@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 12:43:33 by ameechan          #+#    #+#             */
/*   Updated: 2024/08/06 12:46:58 by ameechan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
Checks if the command line arguments are valid, if the file is a .ber file,
and if the file can be opened.

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
		ft_printf("Error\nCould not open file %s\n", argv[1]);
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
