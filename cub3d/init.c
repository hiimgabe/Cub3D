/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmagalha <pmagalha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 14:42:56 by pmagalha          #+#    #+#             */
/*   Updated: 2024/07/10 10:42:12 by pmagalha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//This is my idea for the init_map and its struct (for now)

t_map	*init_map(t_map *map)
{
	map->layout = NULL;
	map->map_height = 0;
	map->map_width = 0;
	map->no = NULL;
	map->so = NULL;
	map->we = NULL;
	map->ea = NULL;
	map->f = NULL;
	map->c = NULL;
	return (map);
}

t_game	*init_game(void)
{
	t_game	*game;
	
	game = malloc(sizeof(t_game));
	if (!game)
		return (ft_putstr_fd("Error: game memory allocation failed.\n", 2), NULL);
	game->map = malloc(sizeof(t_map));
	if (!game->map)
	{
		free_game(game);
		return (ft_putstr_fd("Error: map memory allocation failed.\n", 2), NULL);
	}
	
	init_map(game->map);
	return (game);
}