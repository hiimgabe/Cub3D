/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabe <gabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 11:34:53 by gabe              #+#    #+#             */
/*   Updated: 2024/10/22 12:39:41 by gabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static int	forward(void)
{
	t_pos	move;
	t_pos	map_pos;

	move.y = game()->player.pos.y + game()->player.dir.y * MOVEMENTSPEED;
	move.x = game()->player.pos.x + game()->player.dir.x * MOVEMENTSPEED;
	map_pos = convert_to_map(move);
	if (game()->map->layout[(int)(map_pos.y - 0.022725)]
			[(int)(map_pos.x - 0.022725)] == '1')
		return (0);
	return (check_move(move));
}

static int	backward(void)
{
	t_pos	map_pos;
	t_pos	move;

	move.y = game()->player.pos.y - game()->player.dir.y * MOVEMENTSPEED;
	move.x = game()->player.pos.x - game()->player.dir.x * MOVEMENTSPEED;
	map_pos = convert_to_map(move);
	if (game()->map->layout[(int)(map_pos.y + 0.022725)]
			[(int)(map_pos.x + 0.022725)] == '1')
		return (0);
	return (check_move(move));
}

static int	right(void)
{
	t_pos	map_pos;
	t_pos	move;

	move.y = game()->player.pos.y + game()->player.dir.x * MOVEMENTSPEED;
	move.x = game()->player.pos.x - game()->player.dir.y * MOVEMENTSPEED;
	map_pos = convert_to_map(move);
	if (game()->map->layout[(int)(map_pos.y - 0.022725)]
			[(int)(map_pos.x + 0.022725)] == '1')
		return (0);
	return (check_move(move));
}

static int	left(void)
{
	t_pos	map_pos;
	t_pos	move;

	move.y = game()->player.pos.y - game()->player.dir.x * MOVEMENTSPEED;
	move.x = game()->player.pos.x + game()->player.dir.y * MOVEMENTSPEED;
	map_pos = convert_to_map(move);
	if (game()->map->layout[(int)(map_pos.y + 0.022725)]
			[(int)(map_pos.x - 0.022725)] == '1')
		return (0);
	return (check_move(move));
}

int	move_player(void)
{
	int	move;

	move = 0;
	if (game()->player.y == 1)
		move += forward();
	if (game()->player.y == -1)
		move += backward();
	if (game()->player.x == 1)
		move += right();
	if (game()->player.x == -1)
		move += left();
	if (game()->player.rotate == 1)
		move += rotate_camera(RIGHT);
	if (game()->player.rotate == -1)
		move += rotate_camera(LEFT);
	return (move);
}
