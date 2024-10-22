/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabe <gabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 12:42:03 by gabe              #+#    #+#             */
/*   Updated: 2024/10/22 14:32:09 by gabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	draw_minimap(void)
{
	int		y;
	int		x;

	y = -1;
	while (game()->map->layout[++y])
	{
		x = -1;
		while (game()->map->layout[y][++x])
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
