/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameechan <ameechan@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 13:19:46 by ameechan          #+#    #+#             */
/*   Updated: 2024/09/16 13:19:49 by ameechan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
draws the player on the map in the correct position
given by the coordinates i and j
*/
void	draw_player(t_data *var, int i, int j)
{
	render_xpm(var, PLAYERPATH, j * 32, i * 32);
}

/*
draws the collectibles on the map in the correct position
given by the coordinates i and j
*/
void	draw_collectible(t_data *var, int i, int j)
{
	render_xpm(var, OBJPATH, j * 32, i * 32);
}

/*
draws walls on the map in the correct position
given by the coordinates i and j
*/
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

/*
draws the exit on the map in the correct position
given by the coordinates i and j
*/
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

/*
draws background tiles on the map in the correct position
given by the coordinates i and j
*/
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
