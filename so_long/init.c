/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameechan <ameechan@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 00:23:02 by ameechan          #+#    #+#             */
/*   Updated: 2024/09/12 00:23:02 by ameechan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_window(t_data *data)
{
	if (data->win)
		mlx_destroy_window(data->mlx, data->win);
	if (data->mlx)
		free(data->mlx);
	exit (0);
}

int	key_hook(int keycode, t_data *data)
{
	ft_printf("keycode: %d\n", keycode);
	if (keycode == ESC_KEY)
		close_window(data);
	return (0);
}

void	init_node(t_map *node)
{
	node->file_path = NULL;
	node->map_str = NULL;
	node->map = NULL;
	node->visited = NULL;
	node->start = NULL;
	node->exit = NULL;
}

int	init_game(t_map *node)
{
	t_data	var;

	var.mlx = mlx_init();
	if (!var.mlx)
		return (-1);
	var.node = node;
	var.win = mlx_new_window(var.mlx, node->width * 32,
			node->height * 32, "My game");
	if (!var.win)
		return (-1);
	mlx_hook(var.win, 17, 0, close_window, &var);
	render_map(&var, node);
	mlx_key_hook(var.win, key_hook, &var);
	mlx_loop(var.mlx);
	return (0);
}

void	render_map(t_data *var, t_map *node)
{
	int	i;
	int	j;

	var->img_ptr = mlx_xpm_file_to_image(var->mlx, BGPATH,
			&var->width, &var->height);
	mlx_put_image_to_window(var->mlx, var->win, var->img_ptr, 0, 1);
	i = 0;
	while (i < node->height)
	{
		j = 0;
		while (j < node->width)
		{
			if (node->map[i][j] == '1')
				draw_wall(var, i, j);
			else if (node->map[i][j] == 'P')
				draw_player(var, i, j);
			else if (node->map[i][j] == 'E')
				draw_exit(var, i, j);
			else if (node->map[i][j] == 'C')
				draw_collectible(var, i, j);
			j++;
		}
		i++;
	}
}

void	draw_xpm_p(t_data *var, char *path, int start_x, int start_y)
{
	int width;
	int	height;

	var->obj_ptr = mlx_xpm_file_to_image( var->mlx, path, &width, &height);

	var->addr = mlx_get_data_addr(var->obj_ptr, &var->bpp, &var->size_line, &var->endian);

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
}

void	draw_player(t_data *var, int i, int j)
{
	draw_xpm_p(var, PLAYERPATH, j * 32, i * 32);
}

void	draw_collectible(t_data *var, int i, int j)
{
	draw_xpm_p(var, OBJPATH, j * 32, i * 32);
}

void	draw_wall(t_data *var, int i, int j)
{
	int	width;
	int	height;

	width = 32;
	height = 32;
	var->wall_ptr = mlx_xpm_file_to_image(var->mlx, WALLPATH, &width, &height);
	mlx_put_image_to_window(var->mlx, var->win, var->wall_ptr, j * 32, i * 32);
}

/* void	draw_player(t_data *var, int i, int j)
{
	int	width;
	int	height;

	width = 32;
	height = 32;
	var->player_ptr = mlx_xpm_file_to_image(var->mlx, PLAYERPATH, &width, &height);
	mlx_put_image_to_window(var->mlx, var->win, var->player_ptr, j * 32, i * 32);
} */

void	draw_exit(t_data *var, int i, int j)
{
	for (int x = 0; x < 32; x++)
	{
	for (int y = 0; y < 32; y++)
		mlx_pixel_put(var->mlx, var->win, j * 32 + x, i * 32 + y, 0x800080);
	}
}

/* void	draw_collectible(t_data *var, int i, int j)
{
	int	width;
	int	height;

	width = 32;
	height = 32;

	var->obj_ptr = mlx_xpm_file_to_image(var->mlx, OBJPATH, &width, &height);
	mlx_put_image_to_window(var->mlx, var->win, var->obj_ptr, j * 32, i * 32);
	for (int x = 0; x < 32; x++)
	{
	for (int y = 0; y < 32; y++)
		mlx_pixel_put(var->mlx, var->win, j * 32 + x, i * 32 + y, 0x0000FF00);
	}
} */
