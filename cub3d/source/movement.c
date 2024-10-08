/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabe <gabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 11:34:53 by gabe              #+#    #+#             */
/*   Updated: 2024/10/08 15:42:17 by gabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static int	forward()
{
	t_pos	move;
	
	move.y = game()->player.pos.y + game()->player.dir.y * MOVEMENTSPEED;
	move.x = game()->player.pos.x + game()->player.dir.x * MOVEMENTSPEED;
	return (check_move(move));
}
static int	backward()
{
	t_pos	move;
	
	move.y = game()->player.pos.y - game()->player.dir.y * MOVEMENTSPEED;
	move.x = game()->player.pos.x - game()->player.dir.x * MOVEMENTSPEED;
	return (check_move(move));
}
static int	right()
{
	t_pos	move;
	
	move.y = game()->player.pos.y + game()->player.dir.x * MOVEMENTSPEED;
	move.x = game()->player.pos.x - game()->player.dir.y * MOVEMENTSPEED;
	return (check_move(move));
}
static int	left()
{
	t_pos	move;
	
	move.y = game()->player.pos.y - game()->player.dir.x * MOVEMENTSPEED;
	move.x = game()->player.pos.x + game()->player.dir.y * MOVEMENTSPEED;
	return (check_move(move));
}

int	move_player()
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
	//if (game()->player.rotate == 1)
	//	return (rotate_right());
	//if (game()->player.rotate == -1)
	//	return (rotate_left());
	return (move);
}