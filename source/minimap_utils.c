/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabe <gabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 12:47:16 by gabe              #+#    #+#             */
/*   Updated: 2024/10/22 14:32:36 by gabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static void	draw_line(t_pos start, t_pos dir, int size, int color)
{
	int	i;

	i = -1;
	while (++i < size)
	{
		render_pixel((t_pos){start.x, start.y}, color);
		start.x += dir.x;
		start.y += dir.y;
	}
}

void	draw_square(t_pos pos, int size, int color)
{
	int	y;
	int	x;

	y = pos.y;
	while (y < pos.y + size)
	{
		x = pos.x;
		while (x < pos.x + size)
			render_pixel((t_pos){x++, y}, color);
		y++;
	}
}

static t_pos	center_pos(t_pos pos, int size)
{
	double	offset;

	offset = (double)size / 2;
	return ((t_pos){pos.x - offset, pos.y - offset});
}

void	draw_player(void)
{
	t_pos	centered_player;
	t_pos	centered_player_map;

	centered_player_map = convert_to_map(game()->player.pos);
	centered_player = center_pos(convert_to_screen(centered_player_map), 5);
	draw_square(centered_player, 5, MINIMAP_P);
}

void	draw_fov(void)
{
	t_pos	centered_pos;
	t_pos	centered_pos_map;
	t_pos	line1;
	t_pos	line2;

	centered_pos_map = convert_to_map(game()->player.pos);
	centered_pos = center_pos(convert_to_screen(centered_pos_map), 1);
	line1.x = game()->player.dir.x - game()->player.cam.x;
	line1.y = game()->player.dir.y - game()->player.cam.y;
	line2.x = game()->player.dir.x + game()->player.cam.x;
	line2.y = game()->player.dir.y + game()->player.cam.y;
	draw_line(centered_pos, line1, 30, MINIMAP_P);
	draw_line(centered_pos, game()->player.dir, 30, MINIMAP_P);
	draw_line(centered_pos, line2, 30, MINIMAP_P);
}
