/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabe <gabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 12:42:03 by gabe              #+#    #+#             */
/*   Updated: 2024/10/14 14:53:32 by gabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static void	draw_line(t_pos start, t_pos dir, int size, int color)
{
	int	i;

	i = -1;
	while (++i < size)
	{
		render_pixel((t_pos){start.x + dir.x, start.y + dir.y}, color);
		start.x += dir.x;
		start.y += dir.y;
	}
}

static void	draw_square(t_pos pos, int size, int color)
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
	return ((t_pos){pos.x + offset, pos.y + offset});
}

static void	draw_player()
{
	t_pos	centered_player;

	centered_player = center_pos(game()->player.pos, 5);
	draw_square(centered_player, 5, MINIMAP_P);
}

static void	draw_fov()
{
	t_pos	centered_pos;
	t_pos	starting_pos;
	t_pos	line1;
	t_pos	line2;

	centered_pos = center_pos(game()->player.pos, TILE_SIZE);
	starting_pos.x = centered_pos.x + game()->player.dir.x;
	starting_pos.y = centered_pos.y + game()->player.dir.y;
	line1.x = game()->player.dir.x - game()->player.cam.x;
	line1.y = game()->player.dir.y - game()->player.cam.y;
	line2.x = game()->player.dir.x + game()->player.cam.x;
	line2.y = game()->player.dir.y + game()->player.cam.y;
	draw_line(starting_pos, line1, 30, MINIMAP_P);
	draw_line(starting_pos, game()->player.dir, 30, MINIMAP_P);
	draw_line(starting_pos, line2, 30, MINIMAP_P);
}

void	draw_minimap()
{
	// iterate through map layout
	int		y;
	int		x;
	
	y = -1;
	while(game()->map->layout[++y])
	{
		x = -1;
		while(game()->map->layout[y][++x])
		{
			if (game()->map->layout[y][x] == '1')
				draw_square(convert_to_screen((t_pos){x, y}), 10, MINIMAP_W);
			else if (game()->map->layout[y][x] == '0')
				draw_square(convert_to_screen((t_pos){x, y}), 10, MINIMAP_F);
		}
	}
	draw_player(); 
	draw_fov();
}