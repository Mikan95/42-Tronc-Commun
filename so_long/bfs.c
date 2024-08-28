/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameechan <ameechan@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 20:03:40 by ameechan          #+#    #+#             */
/*   Updated: 2024/08/28 20:03:40 by ameechan         ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	bfs(char **map, int map_height, int map_width)
{
	s_pos	*start_pos;

	(void)map_height;
	(void)map_width;
	start_pos = malloc(sizeof(s_pos));
	if (!start_pos)
		ft_perror("Error\nMemory allocation failure\n");
	find_start(map, start_pos);
	ft_printf("start position is (%d:%d)\n", start_pos->column, start_pos->row);

}

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
