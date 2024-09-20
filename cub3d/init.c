/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabe <gabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 14:42:56 by pmagalha          #+#    #+#             */
/*   Updated: 2024/09/20 16:03:28 by gabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//This is my idea for the init_map and its struct (for now)

t_map	*init_map(t_map *map)
{
	map->layout = NULL;
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
		error_exit("struct map error");
	(game())->texture_info = ft_calloc(1, sizeof(t_texture_info));
	if (!game()->texture_info)
		error_exit("struct textures info error");
	game()->map = init_map(game()->map);
	game()->textures = ft_calloc(5, sizeof(int*));
}

void	init_mlx()
{
	t_img	screen_buffer;
	
	game()->mlx = mlx_init();
	if (!game()->mlx)
		return (error_exit("Failed to init mlx."));
	mlx_get_screen_size(game()->mlx, &game()->screenSizex, &game()->screenSizey);
	printf("screen size : %d x %d\n", game()->screenSizey, game()->screenSizex);
	game()->mlx_win = mlx_new_window(game()->mlx, game()->screenSizex, game()->screenSizey, "CUB3D");
	if (!game()->mlx_win)
		return (error_exit("Failed to init mlx window."));
	screen_buffer.img = mlx_new_image(game()->mlx, game()->screenSizex, game()->screenSizey);
	screen_buffer.addr = (int *)mlx_get_data_addr(screen_buffer.img, &screen_buffer.bpp, &screen_buffer.size_line, &screen_buffer.endian);
	game()->screen_buffer = screen_buffer;
}
