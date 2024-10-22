/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabe <gabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 10:22:08 by pmagalha          #+#    #+#             */
/*   Updated: 2024/10/22 13:41:05 by gabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static void	free_map_char(void)
{
	free(game()->map->no);
	free(game()->map->so);
	free(game()->map->ea);
	free(game()->map->we);
	free(game()->map->c);
	free(game()->map->f);
}

static void	free_map(t_map *map)
{
	int	i;

	if (map)
	{
		if (map && map->layout)
		{
			i = 0;
			while (map->layout[i])
			{
				free(map->layout[i]);
				i++;
			}
			free(map->layout);
		}
	}
	free_map_char();
}

static void	free_mlx(void)
{
	if (game()->mlx_win)
		mlx_destroy_window(game()->mlx, game()->mlx_win);
	if (game()->mlx)
		free(game()->mlx);
}

static void	free_textures(void)
{
	int	i;

	i = -1;
	while (++i < 5)
		free(game()->textures[i]);
	free(game()->textures);
}

void	free_game(void)
{
	if (game()->map)
	{
		free_map(game()->map);
		free(game()->map);
		game()->map = NULL;
	}
	if (game()->texture_info)
		free(game()->texture_info);
	if (game()->textures)
		free_textures();
	if (game()->screen_buffer.img)
		mlx_destroy_image(game()->mlx, game()->screen_buffer.img);
	if (game()->mlx)
		free_mlx();
}
