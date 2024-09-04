/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs_prep.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameechan <ameechan@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 16:03:15 by ameechan          #+#    #+#             */
/*   Updated: 2024/09/04 16:03:19 by ameechan         ###   ########.ch       */
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
void	copy_malloc(char ***map_copy, t_map *node)
{
	int	i;

	i = 0;
	*map_copy = malloc(sizeof(char *) * (node->height + 1));
	if (!(*map_copy))
		ft_perror("Error\nmap_copy memory allocation problem\n");
	(*map_copy)[node->height] = NULL;
	while (i < node->height)
	{
		(*map_copy)[i] = malloc(sizeof(char) * node->width + 1);
		if (!(*map_copy)[i])
			ft_perror("Error\nmap_copy memory allocation problem\n");
		i++;
	}
}

/*
Finds the position of `P` in `map` and stores its coordinates
in `start_pos` struct
*/
void	find_start(char **map, t_map *node)
{
	int	i;
	int	j;
	t_pos	*start;

	start = malloc(sizeof(t_pos));
	if (!start)
		ft_perror("Error\nMemory allocation failure\n");
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
			{
				start->row = i;
				start->column = j;
			}
			j++;
		}
		i++;
	}
	node->start = start;
}

/*
Creates a copy of map** and stores position of `P` in `start_pos` struct
then intiates bfs()
*/
void	bfs_prep(t_map *node)
{
	char	**map_copy;

	map_copy = NULL;
	find_start(node->map, node);
	ft_printf("node->start: (%d:%d)\n", node->start->row, node->start->column);
	copy_malloc(&map_copy, node);
	copy_map(node->map, map_copy);
	bfs(map_copy, node);
}
