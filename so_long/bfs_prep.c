/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs_prep.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameechan <ameechan@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 20:03:40 by ameechan          #+#    #+#             */
/*   Updated: 2024/09/02 18:53:35 by ameechan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
copies the contents of map_src to map_copy (includes termintaing '\0')
*/
void	copy_map(char **map_src, char **map_copy)
{
	int	i;
	int	j;

	i = 0;
	while (map_src[i])
	{
		j = 0;
		while (map_src[i][j])
		{
			map_copy[i][j] = map_src[i][j];
			j++;
		}
		i++;
	}
	i = 0;
/* 	while (map_copy[i])
	{
		ft_printf("map_copy[%d]: %s\n", i, map_copy[i]);
		i++;
	} */
}

/*
Creates a 2d array big enough to store a copy of the contents of map inside it
*/
void	copy_malloc(char ***map_copy, int height, int width)
{
	int	i;

	i = 0;
	*map_copy = malloc(sizeof(char *) * (height + 1));
	if (!(*map_copy))
		ft_perror("Error\nmap_copy memory allocation problem\n");
	(*map_copy)[height] = NULL;
	while (i < height)
	{
		(*map_copy)[i] = malloc(sizeof(char) * width + 1);
		if (!(*map_copy)[i])
			ft_perror("Error\nmap_copy memory allocation problem\n");
		i++;
	}
}

/*
Finds the position of `P` in `map` and stores its coordinates
in `start_pos` struct
*/
void	find_start(char **map, s_pos *start_pos)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
			{
				start_pos->row = i;
				start_pos->column = j;
			}
			j++;
		}
		i++;
	}
}

/*
Creates a copy of map** and stores position of `P` in `start_pos` struct
then intiates bfs()
*/
void	bfs_prep(char **map, int map_height, int map_width)
{
	s_pos	*start_pos;
	char	**map_copy;

	map_copy = NULL;
	start_pos = malloc(sizeof(s_pos));
	if (!start_pos)
		ft_perror("Error\nMemory allocation failure\n");
	find_start(map, start_pos);
	copy_malloc(&map_copy, map_height, map_width);
	copy_map(map, map_copy);
	bfs(map_copy, *start_pos, map_width, map_height);
	free(start_pos);
}
