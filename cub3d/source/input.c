/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabe <gabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 14:42:21 by gabe              #+#    #+#             */
/*   Updated: 2024/10/22 12:38:13 by gabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	handle_input(int key)
{
	if (key == 65307)
		exit_free();
	if (key == 119)
		game()->player.y += 1;
	if (key == 97)
		game()->player.x += -1;
	if (key == 115)
		game()->player.y += -1;
	if (key == 100)
		game()->player.x += 1;
	if (key == 65363)
		game()->player.rotate += 1;
	if (key == 65361)
		game()->player.rotate += -1;
	if (key == 32)
		game()->player.minimap = !game()->player.minimap;
	if (key == 102)
		game()->player.fps = !game()->player.fps;
	return (0);
}

int	input_release(int key)
{
	if (key == 65307)
		exit_free();
	if (key == 119 && game()->player.y >= 1)
		game()->player.y = 0;
	if (key == 97 && game()->player.x <= -1)
		game()->player.x = 0;
	if (key == 115 && game()->player.y <= -1)
		game()->player.y = 0;
	if (key == 100 && game()->player.x >= 1)
		game()->player.x = 0;
	if (key == 65363)
		game()->player.rotate = 0;
	if (key == 65361)
		game()->player.rotate = 0;
	game()->player.moving = 0;
	return (0);
}
