/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabe <gabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 10:01:07 by gabe              #+#    #+#             */
/*   Updated: 2024/10/23 10:06:48 by gabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static void	wrap_mouse(int x, int y)
{
	if (x > SCREEN_W - MOUSEWRAP)
	{
		x = SCREEN_W - MOUSEWRAP;
		mlx_mouse_move(game()->mlx, game()->mlx_win, x ,y);
	}
	else if (x < MOUSEWRAP)
	{
		x = MOUSEWRAP;
		mlx_mouse_move(game()->mlx, game()->mlx_win, x ,y);
	}
}

int	mouse_handler(int x, int y)
{
	static int	oldx;

	oldx = SCREEN_W / 2;
	wrap_mouse(x, y);
	if (x == oldx)
		return (0);
	else if (x > oldx)
		game()->player.rotate += rotate_camera(RIGHT);
	else if (x < oldx)
		game()->player.rotate += rotate_camera(LEFT);
	oldx = x;
	return (0);
}