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

#include <mlx.h>
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
//	printf("keycode: %d\n", keycode);
	if (keycode == ESC_KEY)
		close_window(data);
	return (0);
}

int	main(void)
{
	t_data	variables;
	char	*path = "./assets/Background.xpm";
	int		img_width;
	int		img_height;

	variables.mlx = mlx_init();
	if (!variables.mlx)
		return (1);
	variables.win = mlx_new_window(variables.mlx, 1024, 768, "My game");
	if (!variables.win)
		return (free(variables.mlx), 1);
	mlx_hook(variables.win, 17, 0, close_window, &variables);
	mlx_key_hook(variables.win, key_hook, &variables);
	variables.img_ptr = mlx_xpm_file_to_image(variables.mlx, path, &img_width, &img_height);
	mlx_put_image_to_window(variables.mlx, variables.win, variables.img_ptr, 0, 0);
	mlx_loop(variables.mlx);
}

//gcc init.c -o init -Iminilibx-linux/ -Lminilibx-linux/ -lmlx -lX11 -lXext
