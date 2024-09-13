/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameechan <ameechan@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 17:56:09 by ameechan          #+#    #+#             */
/*   Updated: 2024/09/13 17:59:37 by ameechan         ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_up(t_data *var)
{
	int	y;
	int	x;

	y = var->node->player->y;
	x = var->node->player->x;
	if (var->node->map[y - 1][x] == '1')
		return ;
	if (var->node->map[y][x] == 'P')
		var->node->map[y][x] = '0';
	if (var->node->map[y - 1][x] == '0')
	{
		var->node->map[y][x] = '0';
		var->node->map[y - 1][x] = 'P';
		var->node->player->y = y - 1;
	}
	else if (var->node->map[y - 1][x] == 'C')
	{
		var->node->map[y][x] = '0';
		var->node->map[y - 1][x] = 'P';
		var->node->player->y = y - 1;
		var->node->c_total--;
	}
	render_map(var, var->node);
}

void	move_down(t_data *var)
{
	int	y;
	int	x;

	y = var->node->player->y;
	x = var->node->player->x;
	if (var->node->map[y + 1][x] == '1')
		return ;
	if (var->node->map[y][x] == 'P')
		var->node->map[y][x] = '0';
	if (var->node->map[y + 1][x] == '0')
	{
		var->node->map[y][x] = '0';
		var->node->map[y + 1][x] = 'P';
		var->node->player->y = y + 1;
	}
	else if (var->node->map[y + 1][x] == 'C')
	{
		var->node->map[y][x] = '0';
		var->node->map[y + 1][x] = 'P';
		var->node->player->y = y + 1;
		var->node->c_total--;
	}
	render_map(var, var->node);
}

void	move_left(t_data *var)
{
	int	y;
	int	x;

	y = var->node->player->y;
	x = var->node->player->x;
	if (var->node->map[y][x - 1] == '1')
		return ;
	if (var->node->map[y][x] == 'P')
		var->node->map[y][x] = '0';
	if (var->node->map[y][x - 1] == '0')
	{
		var->node->map[y][x] = '0';
		var->node->map[y][x - 1] = 'P';
		var->node->player->x = x - 1;
	}
	else if (var->node->map[y][x - 1] == 'C')
	{
		var->node->map[y][x] = '0';
		var->node->map[y][x - 1] = 'P';
		var->node->player->x = x - 1;
		var->node->c_total--;
	}
	render_map(var, var->node);
}

void	move_right(t_data *var)
{
	int	y;
	int	x;

	y = var->node->player->y;
	x = var->node->player->x;
	if (var->node->map[y][x + 1] == '1')
		return ;
	if (var->node->map[y][x] == 'P')
		var->node->map[y][x] = '0';
	if (var->node->map[y][x + 1] == '0')
	{
		var->node->map[y][x] = '0';
		var->node->map[y][x + 1] = 'P';
		var->node->player->x = x + 1;
	}
	else if (var->node->map[y][x + 1] == 'C')
	{
		var->node->map[y][x] = '0';
		var->node->map[y][x + 1] = 'P';
		var->node->player->x = x + 1;
		var->node->c_total--;
	}
	render_map(var, var->node);
}
