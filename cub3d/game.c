/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabe <gabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 14:32:55 by gabe              #+#    #+#             */
/*   Updated: 2024/09/25 12:41:53 by gabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	start_game()
{
	// start mlx
	init_mlx();
	// load textures
	load_textures();
	load_player();
	printf("Player is at : x %f, y %f facing %c\n", game()->player->pos.x, game()->player->pos.y, game()->player->dir);
	mlx_hook(game()->mlx_win, KeyPress, KeyPressMask, handle_input, NULL);
	mlx_loop_hook(game()->mlx, render_game, NULL);
	mlx_loop(game()->mlx);
}