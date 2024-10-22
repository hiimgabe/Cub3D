/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabe <gabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 13:10:16 by gabe              #+#    #+#             */
/*   Updated: 2024/10/22 12:08:33 by gabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	rotate_camera(t_rotation rotation)
{
	double		rotspeed;
	t_player	*p;

	rotspeed = ROTSPEED;
	if (rotation == LEFT)
		rotspeed = -rotspeed;
	p = &game()->player;
	p->dir.x = p->dir.x * cos(rotspeed) - p->dir.y * sin(rotspeed);
	p->dir.y = p->dir.x * sin(rotspeed) + p->dir.y * cos(rotspeed);
	p->cam.x = p->cam.x * cos(rotspeed) - p->cam.y * sin(rotspeed);
	p->cam.y = p->cam.x * sin(rotspeed) + p->cam.y * cos(rotspeed);
	game()->player.moving = 1;
	return (EXIT_SUCCESS);
}
