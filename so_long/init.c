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

int	main(void)
{
	void	*mlx;
	void	*mlx_win;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1024, 768, "Hello world!");
	(void)mlx_win;
	mlx_loop(mlx);
}

//gcc init.c -o init -Iminilibx-linux/ -Lminilibx-linux/ -lmlx -lX11 -lXext
