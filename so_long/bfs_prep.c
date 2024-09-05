/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs_prep.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameechan <ameechan@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 18:13:53 by ameechan          #+#    #+#             */
/*   Updated: 2024/09/05 18:14:03 by ameechan         ###   ########.ch       */
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
		map_copy[i][j] = '\0';
		i++;
	}
	i = 0;
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
				start->y = i;
				start->x = j;
			}
			j++;
		}
		i++;
	}
	node->start = start;
}

/*
Creates a copy of map**, finds and stores position of `P` in node
sets c_bfs to 0 in preparation for bfs
*/
void	bfs_prep(t_map *node)
{
	char	**map_copy;
	map_copy = NULL;
	find_start(node->map, node);
	copy_malloc(&map_copy, node);
	copy_map(node->map, map_copy);
	node->visited = map_copy;
	node->c_bfs = 0;
	node->e_bfs = 0;
}
