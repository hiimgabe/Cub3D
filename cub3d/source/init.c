/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabe <gabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 14:42:56 by pmagalha          #+#    #+#             */
/*   Updated: 2024/10/22 19:20:37 by gabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	init_game(void)
{
	(game())->map = ft_calloc(1, sizeof(t_map));
	if (!game()->map)
		error_exit(ERR_STRUCTINIT, NULL);
	(game())->texture_info = ft_calloc(1, sizeof(t_texture_info));
	if (!game()->texture_info)
		error_exit(ERR_TXTINFO, NULL);
	game()->map->layout = NULL;
	(game())->textures = ft_calloc(5, sizeof(int *));
}

void	init_mlx(void)
{
	t_img	screen_buffer;

	game()->mlx = mlx_init();
	if (!game()->mlx)
		return (error_exit(ERR_MLXINIT, NULL));
	game()->mlx_win = mlx_new_window(game()->mlx, SCREEN_W, SCREEN_H, "CUB3D");
	if (!game()->mlx_win)
		return (error_exit(ERR_MLXWIN, NULL));
	screen_buffer.img = mlx_new_image(game()->mlx, SCREEN_W, SCREEN_H);
	screen_buffer.addr = (int *)mlx_get_data_addr(screen_buffer.img,
			&screen_buffer.bpp, &screen_buffer.size_line,
			&screen_buffer.endian);
	game()->screen_buffer = screen_buffer;
}
