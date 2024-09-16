/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameechan <ameechan@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 13:20:45 by ameechan          #+#    #+#             */
/*   Updated: 2024/09/16 13:20:57 by ameechan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
checks and frees all elements accordingly
before printing an error message and exiting the program
*/
void	free_elements(t_map *node, char *errmsg)
{
	if (!node)
		return ;
	if (node->map)
		free_map(node->map);
	ft_printf("freed map\n");
	if (node->visited)
		free_map(node->visited);
	ft_printf("freed visited\n");
	if (node->map_str)
		free(node->map_str);
	ft_printf("freed map_str\n");
	if (node->exit)
		free(node->exit);
	ft_printf("freed exit\n");
	if (node->start)
		free(node->start);
	ft_printf("freed start\n");
	free(node);
	ft_printf("freed node\n");
	ft_printf("%s", errmsg);
	exit (1);
}

/*
frees the contents of a 2d array
*/
void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}
