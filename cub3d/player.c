/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabe <gabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 10:33:14 by gabe              #+#    #+#             */
/*   Updated: 2024/09/25 15:19:41 by gabe             ###   ########.fr       */
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
					game()->player->dir = game()->map->layout[y][x];
					return ;
				}
		}
	}
}

void	load_player()
{
	set_player_pos();
	
}