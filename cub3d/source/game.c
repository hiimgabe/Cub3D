/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabe <gabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 14:32:55 by gabe              #+#    #+#             */
/*   Updated: 2024/10/22 12:43:40 by gabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	start_game(void)
{
	init_mlx();
	load_textures();
	mlx_hook(game()->mlx_win, KeyPress, KeyPressMask, handle_input, NULL);
	mlx_hook(game()->mlx_win, KeyRelease, KeyReleaseMask, input_release, NULL);
	mlx_loop_hook(game()->mlx, render_game, NULL);
	load_player();
	mlx_loop(game()->mlx);
}
