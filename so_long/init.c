/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameechan <ameechan@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 16:19:10 by ameechan          #+#    #+#             */
/*   Updated: 2024/07/19 16:19:10 by ameechan         ###   ########.fr       */
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
//	ft_printf("keycode: %d\n", keycode);
	if (keycode == ESC_KEY)
		close_window(data);
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	var;
	char	*path = "./assets/Background.xpm";
	int		img_width;
	int		img_height;
	int		fd;

	fd = arg_check(argc, argv);
	ft_printf("first line of %s is:\n%s\n", argv[1], get_next_line(fd));
	var.mlx = mlx_init();
	if (!var.mlx)
		return (1);
	var.win = mlx_new_window(var.mlx, 1024, 768, "My game");
	if (!var.win)
		return (free(var.mlx), 1);
	mlx_hook(var.win, 17, 0, close_window, &var);
	mlx_key_hook(var.win, key_hook, &var);
	var.img_ptr = mlx_xpm_file_to_image(var.mlx, path, &img_width, &img_height);
	mlx_put_image_to_window(var.mlx, var.win, var.img_ptr, 0, 0);
	mlx_loop(var.mlx);
}

//gcc init.c -o init -Iminilibx-linux/ -Lminilibx-linux/ -lmlx -lX11 -lXext
