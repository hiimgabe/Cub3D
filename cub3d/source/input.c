/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabe <gabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 14:42:21 by gabe              #+#    #+#             */
/*   Updated: 2024/10/08 15:51:56 by gabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	handle_input(int key)
{
	if (key == 65307)
		exit(42);
	else if (key == 119)// W
		game()->player.y += 1;
	else if (key == 97)// A
		game()->player.x += -1;
	else if (key == 115)// S
		game()->player.y += -1;
	else if (key == 100)// D
		game()->player.x += 1;
	else if (key == 65363)// ->
		game()->player.rotate += 1;
	else if (key == 65361)// <-
		game()->player.rotate += -1;
	return (0);
}

int	input_release(int key)
{
	if (key == 65307)
		exit(42);
	else if (key == 119 && game()->player.y >= 1)// W
		game()->player.y = 0;
	else if (key == 97 && game()->player.x <= -1)// A
		game()->player.x = 0;
	else if (key == 115 && game()->player.y <= -1)// S
		game()->player.y = 0;
	else if (key == 100 && game()->player.x >= 1)// D
		game()->player.x = 0;
	//else if (key == 65363)// ->
	//	game()->player.rotate += 1;
	//else if (key == 65361)// <-
	//	game()->player.rotate += -1;
	return (0);
}