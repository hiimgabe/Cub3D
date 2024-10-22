/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabe <gabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 14:47:32 by gabe              #+#    #+#             */
/*   Updated: 2024/10/22 14:37:45 by gabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	render_pixel(t_pos pos, int color)
{
	char	*dst;
	t_img	img;

	img = game()->screen_buffer;
	dst = (char *)img.addr + ((int)pos.y
			* img.size_line + (int)pos.x * (img.bpp / 8));
	*(unsigned int *)dst = color;
}

static void	render_floor(void)
{
	int	y;
	int	x;

	y = SCREEN_H / 2 - 1;
	while (++y < SCREEN_H)
	{
		x = -1;
		while (++x < SCREEN_W)
			render_pixel((t_pos){x, y},
				shader_floor(y, game()->texture_info->f));
	}
}

static void	render_ceiling(void)
{
	int	y;
	int	x;

	y = -1;
	while (++y < SCREEN_H / 2)
	{
		x = -1;
		while (++x < SCREEN_W)
			render_pixel((t_pos){x, y},
				shader_ceiling(y, game()->texture_info->c));
	}
}

static void	clear_screen(void)
{
	int	i;
	int	j;

	i = -1;
	while (++i < SCREEN_H)
	{
		j = -1;
		while (++j < SCREEN_W)
			render_pixel((t_pos){j, i}, 0x00000000);
	}
}

int	render_game(void)
{
	long int	old_time;

	old_time = get_time();
	game()->player.moving += move_player();
	clear_screen();
	render_ceiling();
	render_floor();
	raycast();
	if (game()->player.minimap)
		draw_minimap();
	mlx_put_image_to_window(game()->mlx,
		game()->mlx_win, game()->screen_buffer.img, 0, 0);
	if (game()->player.fps)
		show_fps(old_time);
	game()->player.moving = 0;
	return (0);
}
