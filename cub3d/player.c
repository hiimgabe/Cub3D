/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabe <gabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 10:33:14 by gabe              #+#    #+#             */
/*   Updated: 2024/09/26 10:20:54 by gabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	set_player_pos()
{
	int		x;
	int		y;

	y = -1;
	while (game()->map->layout[++y])
	{
		x = -1;
		while (game()->map->layout[y][++x] != '\0')
		{
			if (game()->map->layout[y][x] == 'N' || game()->map->layout[y][x] == 'S'
				|| game()->map->layout[y][x] == 'E' || game()->map->layout[y][x] == 'W')
			{
				game()->player->compass = game()->map->layout[y][x];
				game()->player->pos = convert_to_screen((t_pos){x, y});
			}
		}
	}
}
static void	set_player_dir()
{
	if (game()->player->compass == 'N')
		game()->player->dir = (t_pos){0, 1};
	else if (game()->player->compass == 'S')
		game()->player->dir = (t_pos){0, -1};
	else if (game()->player->compass == 'E')
		game()->player->dir = (t_pos){1, 0};
	else if (game()->player->compass == 'W')
		game()->player->dir = (t_pos){-1, 0};
}
static void	set_player_cam()
{
	if (game()->player->compass == 'N')
		game()->player->cam = (t_pos){0, 0.66};
	else if (game()->player->compass == 'S')
		game()->player->cam = (t_pos){0, -0.66};
	else if (game()->player->compass == 'E')
		game()->player->cam = (t_pos){0.66, 0};
	else if (game()->player->compass == 'W')
		game()->player->cam = (t_pos){-0.66, 0};
}

void	load_player()
{
	set_player_pos();
	set_player_dir();
	set_player_cam();
}