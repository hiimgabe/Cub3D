/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shaders.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabe <gabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 09:42:04 by gabe              #+#    #+#             */
/*   Updated: 2024/10/22 14:45:00 by gabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static void	set_texture_index(t_ray *ray)
{
	if (!ray->side)
	{
		if (ray->dir.x < 0)
			game()->texture_info->index = WEST;
		else
			game()->texture_info->index = EAST;
	}
	else
	{
		if (ray->dir.y < 0)
			game()->texture_info->index = NORTH;
		else
			game()->texture_info->index = SOUTH;
	}
}

void	render_texture(t_ray *ray, int x)
{
	t_texture_info	*text;
	int				y;
	int				color;

	text = game()->texture_info;
	set_texture_index(ray);
	text->x = (int)(ray->wall_x * (double)text->size);
	text->step = (double)text->size / ray->line_height;
	text->pos = (ray->start - (double)SCREEN_W / 2
			+ (double)ray->line_height / 2) * text->step;
	y = ray->start;
	while (y < ray->end)
	{
		text->y = (int)text->pos & (text->size - 1);
		text->pos += text->step;
		color = game()->textures[text->index][text->size * text->y + text->x];
		if (text->index == SOUTH || text->index == NORTH)
			color = (color >> 1) & 8355711;
		color = shader(ray->perp_wall_dist, color);
		render_pixel((t_pos){x, y}, color);
		y++;
	}
}

int	shader(double wall_dist, int color)
{
	double	attenuation_coef;

	if (wall_dist > RENDER_DIST)
		return (0x00000000);
	attenuation_coef = (RENDER_DIST - wall_dist) / RENDER_DIST;
	return (get_trgb(0, (int)(attenuation_coef
			* ((color >> 16) & 0xFF)), (int)(attenuation_coef
		* ((color >> 8) & 0xFF)), (int)(attenuation_coef * (color & 0xFF))));
}

int	shader_ceiling(int dist, int color)
{
	double	attenuation_coef;
	double	halve;

	halve = SCREEN_H / 2;
	attenuation_coef = (halve - dist) / halve;
	return (get_trgb(0, (int)(attenuation_coef
			* ((color >> 16) & 0xFF)), (int)(attenuation_coef
		* ((color >> 8) & 0xFF)), (int)(attenuation_coef * (color & 0xFF))));
}

int	shader_floor(int dist, int color)
{
	double	attenuation_coef;
	double	halve;

	halve = SCREEN_H / 2;
	attenuation_coef = (dist - halve) / halve;
	return (get_trgb(0, (int)(attenuation_coef
			* ((color >> 16) & 0xFF)), (int)(attenuation_coef
		* ((color >> 8) & 0xFF)), (int)(attenuation_coef * (color & 0xFF))));
}
