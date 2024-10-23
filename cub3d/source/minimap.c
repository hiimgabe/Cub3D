/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabe <gabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 12:42:03 by gabe              #+#    #+#             */
/*   Updated: 2024/10/23 12:06:32 by gabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	print_map(char **map)
{
	int	i;
	int	j;

	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
			printf("%c", map[i][j]);
		printf("\n");
	}
}

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
