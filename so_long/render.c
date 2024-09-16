/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameechan <ameechan@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 12:35:37 by ameechan          #+#    #+#             */
/*   Updated: 2024/09/16 12:35:49 by ameechan         ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
/*
checks if all collectibles in the game have been collected
if yes, it changes the exit tile to 'E'
*/
void	check_collectibles(t_map *node, int c_total, t_pos *exit)
{
	if (c_total == 0)
	{
		node->map[exit->y][exit->x] = 'E';
	}
}

/*
iterates through the map and renders the game
making sure to draw thebackground on all tiles other than walls
*/
void	render_map(t_data *var, t_map *node)
{
	int	i;
	int	j;

	check_collectibles(node, node->c_total, node->exit);
	i = 0;
	while (i < node->height)
	{
		j = 0;
		while (j < node->width)
		{
			if (node->map[i][j] != '1')
				draw_bg(var, i, j);
			if (node->map[i][j] == '1')
				draw_wall(var, i, j);
			else if (node->map[i][j] == 'E' && node->c_total == 0)
				draw_exit(var, i, j);
			else if (node->map[i][j] == 'C')
				draw_collectible(var, i, j);
			else if (node->map[i][j] == 'P')
				draw_player(var, i, j);
			j++;
		}
		i++;
	}
}

/*
Renders xpm images pixel by pixel (ignoring transparent pixels)
mlx_xpm_file_to_image & mlx_put_image_to_window had issues with transparency
*/
void	render_xpm(t_data *var, char *path, int start_x, int start_y)
{
	int width;
	int	height;

	var->img_ptr = mlx_xpm_file_to_image( var->mlx, path, &width, &height);

	var->addr = mlx_get_data_addr(var->img_ptr, &var->bpp, &var->size_line, &var->endian);

	int x = 0;
	while (x < width)
	{
		int y = 0;
		while (y < height)
		{
			var->pixel = (y * var->size_line) + (x * (var->bpp / 8));
			var->colour = *(int *)(var->addr + var->pixel);
			if ((var->colour & 0xFF000000) != 0xFF000000)
				mlx_pixel_put(var->mlx, var->win, start_x + x, start_y + y, var->colour);
			y++;
		}
		x++;
	}
	mlx_destroy_image(var->mlx, var->img_ptr);
}

/*
renders the end screen when the player reaches the exit
*/
void	render_end(t_data *var)
{
	mlx_clear_window(var->mlx, var->win);
	mlx_string_put(var->mlx, var->win, 100, 100, 0x00FF0000, "You have reached the exit!");
	mlx_string_put(var->mlx, var->win, 100, 120, 0x00FF0000, "Total moves: ");
	mlx_string_put(var->mlx, var->win, 200, 120, 0x00FF0000, ft_itoa(var->node->move_count));
	mlx_string_put(var->mlx, var->win, 100, 140, 0x00FF0000, "Press ESC to exit");
}
