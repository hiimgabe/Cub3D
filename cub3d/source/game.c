/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabe <gabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 14:32:55 by gabe              #+#    #+#             */
/*   Updated: 2024/10/08 10:25:00 by gabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	start_game()
{
	game()->player.moving = true;
	// start mlx
	init_mlx();
	// load textures
	load_textures();
	mlx_hook(game()->mlx_win, KeyPress, KeyPressMask, handle_input, NULL);
	mlx_loop_hook(game()->mlx, render_game, NULL);
	load_player();
	mlx_loop(game()->mlx);
}