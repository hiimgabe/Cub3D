/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabe <gabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 10:33:14 by gabe              #+#    #+#             */
/*   Updated: 2024/10/22 12:35:03 by gabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static void	set_player_pos(void)
{
	int		x;
	int		y;

	y = -1;
	while (game()->map->layout[++y])
	{
		x = -1;
		while (game()->map->layout[y][++x] != '\0')
		{
			if (game()->map->layout[y][x] == 'N'
				|| game()->map->layout[y][x] == 'S'
				|| game()->map->layout[y][x] == 'E'
				|| game()->map->layout[y][x] == 'W')
			{
				game()->player.compass = game()->map->layout[y][x];
				(game())->player.pos = convert_to_screen((t_pos){x, y});
			}
		}
	}
}

static void	set_player_dir(t_pos pos)
{
	if (game()->map->layout[(int)pos.y][(int)pos.x] == 'N')
		(game())->player.dir = (t_pos){0, -1.01};
	if (game()->map->layout[(int)pos.y][(int)pos.x] == 'S')
		(game())->player.dir = (t_pos){0, 1.01};
	if (game()->map->layout[(int)pos.y][(int)pos.x] == 'W')
		(game())->player.dir = (t_pos){-1.01, 0};
	if (game()->map->layout[(int)pos.y][(int)pos.x] == 'E')
		(game())->player.dir = (t_pos){1.01, 0};
}

static void	set_player_cam(t_pos pos)
{
	if (game()->map->layout[(int)pos.y][(int)pos.x] == 'N')
		(game())->player.cam = (t_pos){0.66, 0};
	if (game()->map->layout[(int)pos.y][(int)pos.x] == 'S')
		(game())->player.cam = (t_pos){-0.66, 0};
	if (game()->map->layout[(int)pos.y][(int)pos.x] == 'W')
		(game())->player.cam = (t_pos){0, -0.66};
	if (game()->map->layout[(int)pos.y][(int)pos.x] == 'E')
		(game())->player.cam = (t_pos){0, 0.66};
}

void	load_player(void)
{
	t_pos	map_pos;

	(game())->player.pos = (t_pos){0.0, 0.0};
	set_player_pos();
	map_pos = convert_to_map(game()->player.pos);
	set_player_dir(map_pos);
	set_player_cam(map_pos);
	game()->map->layout[(int)map_pos.y][(int)map_pos.x] = '0';
	game()->player.moving = 1;
	game()->player.minimap = false;
	game()->player.fps = false;
	game()->player.x = 0;
	game()->player.y = 0;
	game()->player.rotate = 0;
}
