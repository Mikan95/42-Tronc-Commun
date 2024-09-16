/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameechan <ameechan@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 13:22:37 by ameechan          #+#    #+#             */
/*   Updated: 2024/09/16 13:22:39 by ameechan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
checks if the player can move up, if yes, moves the player up,
updates the map to reflect the move and renders the map.
finally, checks if the player has reached the exit,
if yes, renders the end screen.
*/
void	move_up(t_data *var)
{
	int	y;
	int	x;

	y = var->node->player->y;
	x = var->node->player->x;
	if (var->node->map[y - 1][x] == '1')
		return ;
	var->node->map[y][x] = '0';
	if (var->node->map[y - 1][x] == '0')
	{
		var->node->map[y - 1][x] = 'P';
		var->node->player->y = y - 1;
	}
	else if (var->node->map[y - 1][x] == 'C')
	{
		var->node->map[y - 1][x] = 'P';
		var->node->player->y = y - 1;
		var->node->c_total--;
	}
	var->node->move_count++;
	render_map(var, var->node);
	if (var->node->map[y - 1][x] == 'E')
		render_end(var);
}

/*
checks if the player can move down, if yes, moves the player down,
updates the map to reflect the move and renders the map.
finally, checks if the player has reached the exit,
if yes, renders the end screen.
*/
void	move_down(t_data *var)
{
	int	y;
	int	x;

	y = var->node->player->y;
	x = var->node->player->x;
	if (var->node->map[y + 1][x] == '1')
		return ;
	var->node->map[y][x] = '0';
	if (var->node->map[y + 1][x] == '0')
	{
		var->node->map[y + 1][x] = 'P';
		var->node->player->y = y + 1;
	}
	else if (var->node->map[y + 1][x] == 'C')
	{
		var->node->map[y + 1][x] = 'P';
		var->node->player->y = y + 1;
		var->node->c_total--;
	}
	var->node->move_count++;
	render_map(var, var->node);
	if (var->node->map[y + 1][x] == 'E')
		render_end(var);
}

/*
checks if the player can move left, if yes, moves the player left,
updates the map to reflect the move and renders the map.
finally, checks if the player has reached the exit,
if yes, renders the end screen.
*/
void	move_left(t_data *var)
{
	int	y;
	int	x;

	y = var->node->player->y;
	x = var->node->player->x;
	if (var->node->map[y][x - 1] == '1')
		return ;
	var->node->map[y][x] = '0';
	if (var->node->map[y][x - 1] == '0')
	{
		var->node->map[y][x - 1] = 'P';
		var->node->player->x = x - 1;
	}
	else if (var->node->map[y][x - 1] == 'C')
	{
		var->node->map[y][x - 1] = 'P';
		var->node->player->x = x - 1;
		var->node->c_total--;
	}
	var->node->move_count++;
	render_map(var, var->node);
	if (var->node->map[y][x - 1] == 'E')
		render_end(var);
}

/*
checks if the player can move right, if yes, moves the player right,
updates the map to reflect the move and renders the map.
finally, checks if the player has reached the exit,
if yes, renders the end screen.
*/
void	move_right(t_data *var)
{
	int	y;
	int	x;

	y = var->node->player->y;
	x = var->node->player->x;
	if (var->node->map[y][x + 1] == '1')
		return ;
	var->node->map[y][x] = '0';
	if (var->node->map[y][x + 1] == '0')
	{
		var->node->map[y][x + 1] = 'P';
		var->node->player->x = x + 1;
	}
	else if (var->node->map[y][x + 1] == 'C')
	{
		var->node->map[y][x + 1] = 'P';
		var->node->player->x = x + 1;
		var->node->c_total--;
	}
	var->node->move_count++;
	render_map(var, var->node);
	if (var->node->map[y][x + 1] == 'E')
		render_end(var);
}
