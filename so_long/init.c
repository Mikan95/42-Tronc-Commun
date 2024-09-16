/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameechan <ameechan@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 12:36:33 by ameechan          #+#    #+#             */
/*   Updated: 2024/09/16 12:38:14 by ameechan         ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
closes the game window and frees all allocated memory
*/
int	close_window(t_data *data)
{
	if (data->win)
		mlx_destroy_window(data->mlx, data->win);
	ft_printf("freed win\n");
	mlx_destroy_display(data->mlx);
	ft_printf("freed display\n");
	if (data->mlx)
		free(data->mlx);
	ft_printf("freed mlx\n");
	free_elements(data->node, "Exiting game\n");
	return (0);
}

/*
key_hook function that handles player movement
*/
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

/*
intializes all data in the t_data struct
*/
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

/*
initializes the game window and renders the map in it's initial stage
*/
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
