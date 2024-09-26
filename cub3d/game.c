/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabe <gabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 14:32:55 by gabe              #+#    #+#             */
/*   Updated: 2024/09/26 10:21:11 by gabe             ###   ########.fr       */
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
	printf("Player is at : x %f, y %f facing %c\n", game()->player->pos.x, game()->player->pos.y, game()->player->compass);
	printf("Player dir : x  %f, y %f\n", game()->player->dir.x, game()->player->dir.y);
	printf("Player cam : x  %f, y %f\n", game()->player->cam.x, game()->player->cam.y);
	mlx_hook(game()->mlx_win, KeyPress, KeyPressMask, handle_input, NULL);
	mlx_loop_hook(game()->mlx, render_game, NULL);
	mlx_loop(game()->mlx);
}