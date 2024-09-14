/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameechan <ameechan@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 19:00:40 by ameechan          #+#    #+#             */
/*   Updated: 2024/09/13 19:00:40 by ameechan         ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_window(t_data *data)
{
	if (data->win)
		mlx_destroy_window(data->mlx, data->win);
	ft_printf("freed win\n");
/* 	if (data->bg_ptr)
		mlx_destroy_image(data->mlx, data->bg_ptr); */
	ft_printf("freed bg\n");
	mlx_destroy_display(data->mlx);
	ft_printf("freed display\n");
	if (data->mlx)
		free(data->mlx);
	ft_printf("freed mlx\n");
	free_elements(data->node, "Exiting game\n");
	return (0);
}

int	key_hook(int keycode, t_data *var)
{
	if (keycode == ESC_KEY)
		close_window(var);
	else if (keycode == W_KEY)
	{
		move_up(var);
		ft_printf("move count: %d\n", var->node->move_count);
	}
	else if (keycode == A_KEY)
	{
		move_left(var);
		ft_printf("move count: %d\n", var->node->move_count);
	}
	else if (keycode == S_KEY)
	{
		move_down(var);
		ft_printf("move count: %d\n", var->node->move_count);
	}
	else if (keycode == D_KEY)
	{
		move_right(var);
		ft_printf("move count: %d\n", var->node->move_count);
	}
	return (0);
}

void	init_data(t_data *var)
{
	var->mlx = NULL;
	var->win = NULL;
	var->img_ptr = NULL;
	var->wall_ptr = NULL;
	var->exit_ptr = NULL;
	var->bg_ptr = NULL;
	var->node = NULL;
}

/* int	game_loop(t_data *var)
{
	mlx_clear_window(var->mlx, var->win);
	render_map(var, var->node);
	return (0);
} */

int	init_game(t_map *node)
{
	t_data	var;

	ft_printf("exit: (%d, %d)\n", node->exit->x, node->exit->y);
	node->move_count = 0;
	init_data(&var);
	var.mlx = mlx_init();
	if (!var.mlx)
		return (-1);
	var.node = node;
	var.win = mlx_new_window(var.mlx, node->width * 32,
			node->height * 32, "My game");
	if (!var.win)
		return (-1);
	render_map(&var, node);
	mlx_hook(var.win, 17, 0, close_window, &var);
	mlx_key_hook(var.win, key_hook, &var);
	mlx_loop(var.mlx);
	return (0);
}

void	check_collectibles(t_map *node, int c_total, t_pos *exit)
{
	if (c_total == 0)
	{
		node->map[exit->y][exit->x] = 'E';
	}
}

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

void	draw_bg(t_data *var, int i, int j)
{
	int	width;
	int	height;

	width = 32;
	height = 32;
	var->bg_ptr = mlx_xpm_file_to_image(var->mlx, BGPATH, &width, &height);
	mlx_put_image_to_window(var->mlx, var->win, var->bg_ptr, j * 32, i * 32);
	mlx_destroy_image(var->mlx, var->bg_ptr);
}

void	draw_xpm_p(t_data *var, char *path, int start_x, int start_y)
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
	mlx_destroy_image(var->mlx, var->wall_ptr);
}

void	draw_exit(t_data *var, int i, int j)
{
	int	width;
	int	height;

	width = 32;
	height = 32;
	var->exit_ptr = mlx_xpm_file_to_image(var->mlx, EXITPATH, &width, &height);
	mlx_put_image_to_window(var->mlx, var->win, var->exit_ptr, j * 32, i * 32);
	mlx_destroy_image(var->mlx, var->exit_ptr);
}
