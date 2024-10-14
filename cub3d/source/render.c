/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabe <gabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 14:47:32 by gabe              #+#    #+#             */
/*   Updated: 2024/10/14 16:11:02 by gabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

/*
	renders a pixel with color at pos{y, x}
*/
void	render_pixel(t_pos pos, int color)
{
	char	*dst;
	t_img	img;

	img = game()->screen_buffer;
	dst = (char *)img.addr + ((int)pos.y * img.size_line + (int)pos.x * (img.bpp / 8));
	*(unsigned int *)dst = color;
}

/*
	iterates thorugh the lower half of the screen to display a color
*/
void	render_floor()
{
	int	y;
	int	x;

	y = SCREEN_H / 2 - 1;
	while (++y < SCREEN_H)
	{
		x = -1;
		while (++x < SCREEN_W)
		{
			//printf("Rendering at %d, %d with color %d\n", y, x, game()->texture_info->c);
			render_pixel((t_pos){x, y}, shader_floor(y, game()->texture_info->f));
		}
	}
}
/*
	iterates thorugh the higher half of the screen to display a color
*/
void	render_ceiling()
{
	int	y;
	int	x;

	y = -1;
	while (++y < SCREEN_H / 2)
	{
		x = -1;
		while (++x < SCREEN_W)
		{
			//printf("Rendering at %d, %d with color %d\n", y, x, game()->texture_info->c);
			render_pixel((t_pos){x, y}, shader_ceiling(y, game()->texture_info->c));
		}
	}
}

void	clear_screen()
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
	game()->player.moving += move_player();
	if (game()->player.moving == 0)
		return (0);
	clear_screen();
	render_ceiling();
	render_floor();
	raycast();
	if (game()->player.minimap)
		draw_minimap();
	mlx_put_image_to_window(game()->mlx, game()->mlx_win, game()->screen_buffer.img, 0, 0);
	game()->player.moving = 0;
	return (0);
}