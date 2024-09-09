/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameechan <ameechan@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 18:11:27 by ameechan          #+#    #+#             */
/*   Updated: 2024/09/09 18:11:27 by ameechan         ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_window(t_data *data)
{
	if (data->win)
		mlx_destroy_window(data->mlx, data->win);
	if (data->mlx)
		free(data->mlx);
	exit(0);
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

int	main(int argc, char **argv)
{
	t_data	var;
	t_map	*node;
	char	*path = "./assets/Background.xpm";//		TEMPORARY

	arg_check(argc, argv);
	node = malloc(sizeof (t_map));
	if (!node)
		free_elements(node, "Error\nMemory allocation failure\n");
	init_node(node);
	node->file_path = argv[1];
	map_check(node);
	var.mlx = mlx_init();
	if (!var.mlx)
		return (1);
	var.win = mlx_new_window(var.mlx, 1024, 768, "My game");
	if (!var.win)
		return (free(var.mlx), 1);
	mlx_hook(var.win, 17, 0, close_window, &var);
	mlx_key_hook(var.win, key_hook, &var);
	var.img_ptr = mlx_xpm_file_to_image(var.mlx, path, &var.width, &var.height);
	mlx_put_image_to_window(var.mlx, var.win, var.img_ptr, 0, 0);
	mlx_loop(var.mlx);
}
