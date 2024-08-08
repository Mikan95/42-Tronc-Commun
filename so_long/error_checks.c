/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_checks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameechan <ameechan@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 12:43:33 by ameechan          #+#    #+#             */
/*   Updated: 2024/08/08 16:43:47 by ameechan         ###   ########.fr       */
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
Checks that only valid characters are used in the map file
Exits the program with an error message if an invalid character is found
*/
int	valid_char(char c)
{
	if (c == '0' || c == '1' || c == 'C' || c == 'E' || c == 'P')
		return (1);
	else
	{
		perror("Error\nInvalid character used in map file");
		exit(1);
	}
	return (0);
}

int	ft_mystrlen(char *str)
{
	int	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

void	same_line_length(char **map)
{
	int	i;
	int	len;
	char	**temp;

	temp = map;
	len = ft_mystrlen(temp[i]);
	while (temp[i])
	{
		if(ft_mystrlen(temp[i]) == len)
			i++;
		else
		{
			perror("Error\nMap is not rectangular or square");
			exit (1);
		}
	}
}


/*
PREVIOUS VERSION OF same_line_length;
{
	int		len1;
	int		len2;
	char	*temp;

	temp = map;
	len1 = ft_mystrlen(temp);
	len2 = ft_mystrlen(++temp);
	ft_printf("len1: %d\n", len1);
	ft_printf("len2: %d\n", len2);
	if (!temp)
		return (1);
	if (len1 == len2)
	{
		ft_printf("Lines %d and %d are the same length\n", i, i+1);
		return (1);
	}
	else
		return (1);
/* 	{
		perror("Error\nMap is not rectangle or square");
		exit(1);
	} */
	return (0);
} */
