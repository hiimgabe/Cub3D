/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_pos.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabe <gabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 09:48:35 by gabe              #+#    #+#             */
/*   Updated: 2024/10/08 10:25:00 by gabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

t_pos	convert_to_screen(t_pos pos)
{
	t_pos	screen_pos;

	screen_pos.x = MAP_POS + (TILE_SIZE * pos.x) + ((double)TILE_SIZE / 2);
	screen_pos.y = MAP_POS + (TILE_SIZE * pos.y) + ((double)TILE_SIZE / 2);
	return (screen_pos);
}

t_pos	convert_to_map(t_pos screen_pos)
{
	t_pos	map_pos;

	map_pos.x = (screen_pos.x - MAP_POS) / TILE_SIZE;
	map_pos.y = (screen_pos.y - MAP_POS) / TILE_SIZE;
	return (map_pos);
}