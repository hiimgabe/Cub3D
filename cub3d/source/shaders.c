/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shaders.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabe <gabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 09:42:04 by gabe              #+#    #+#             */
/*   Updated: 2024/10/08 10:25:00 by gabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	shader(double wall_dist, int color)
{
	double	attenuation_coef;

	if (wall_dist > RENDER_DIST)
		return (0x00000000);// BLACK
	attenuation_coef = (RENDER_DIST - wall_dist) / RENDER_DIST;
	return (get_trgb(0, (int)(attenuation_coef * ((color >> 16) & 0xFF)), (int)(attenuation_coef * ((color >> 8) & 0xFF)), (int)(attenuation_coef * (color & 0xFF))));
}

int	shader_ceiling(int dist, int color)
{
	double	attenuation_coef;
	double	halve;

	halve = SCREEN_H / 2;
	attenuation_coef = (halve - dist) / halve;
	return (get_trgb(0, (int)(attenuation_coef * ((color >> 16) & 0xFF)), (int)(attenuation_coef * ((color >> 8) & 0xFF)), (int)(attenuation_coef * (color & 0xFF))));
}

int	shader_floor(int dist, int color)
{
	double	attenuation_coef;
	double	halve;

	halve = SCREEN_H / 2;
	attenuation_coef = (dist - halve) / halve;
	return (get_trgb(0, (int)(attenuation_coef * ((color >> 16) & 0xFF)), (int)(attenuation_coef * ((color >> 8) & 0xFF)), (int)(attenuation_coef * (color & 0xFF))));
}
