/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabe <gabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 14:32:55 by gabe              #+#    #+#             */
/*   Updated: 2024/10/23 10:17:52 by gabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	start_game(void)
{
	init_mlx();
	load_textures();
	mlx_hook(game()->mlx_win, KeyPress, KeyPressMask, handle_input, NULL);
	mlx_hook(game()->mlx_win, KeyRelease, KeyReleaseMask, input_release, NULL);
	mlx_hook(game()->mlx_win, DestroyNotify,
		StructureNotifyMask, quit_window, NULL);
	mlx_hook(game()->mlx_win, MotionNotify,
		PointerMotionMask, mouse_handler, NULL);
	mlx_loop_hook(game()->mlx, render_game, NULL);
	load_player();
	mlx_loop(game()->mlx);
}
