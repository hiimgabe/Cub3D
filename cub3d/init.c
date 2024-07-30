/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabe <gabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 14:42:56 by pmagalha          #+#    #+#             */
/*   Updated: 2024/07/30 14:39:32 by gabe             ###   ########.fr       */
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

void	init_game(void)
{	
	game()->map = ft_calloc(1, sizeof(t_map));
	if (!game()->map)
	{
		free_game();
		ft_putstr_fd("Error: map memory allocation failed.\n", 2);
		exit (1);
	}
	init_map(game()->map);
}

void	init_mlx()
{
	game()->mlx = mlx_init();
	game()->mlx_win = mlx_new_window(game()->mlx, 800, 800, "CUB3D");
}