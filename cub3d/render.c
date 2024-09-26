/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabe <gabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 14:47:32 by gabe              #+#    #+#             */
/*   Updated: 2024/09/26 09:57:17 by gabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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

	y = game()->screenSizey / 2 - 1;
	while (++y < game()->screenSizey)
	{
		x = -1;
		while (++x < game()->screenSizex)
		{
			//printf("Rendering at %d, %d with color %d\n", y, x, game()->texture_info->c);
			render_pixel((t_pos){x, y}, game()->texture_info->f);
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
	while (++y < game()->screenSizey / 2)
	{
		x = -1;
		while (++x < game()->screenSizex)
		{
			//printf("Rendering at %d, %d with color %d\n", y, x, game()->texture_info->c);
			render_pixel((t_pos){x, y}, game()->texture_info->c);
		}
	}
}

int	render_game(void)
{
	render_ceiling();
	render_floor();
	raycast();
	mlx_put_image_to_window(game()->mlx, game()->mlx_win, game()->screen_buffer.img, 0, 0);
	return (0);
}