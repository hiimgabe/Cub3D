/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabe <gabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 11:51:20 by gabe              #+#    #+#             */
/*   Updated: 2024/10/11 16:01:26 by gabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static int	get_map_width(int y)
{
	if (!game()->map->layout[y])
		return (0);
	return (ft_strlen(game()->map->layout[y]));
}

static int	get_map_height()
{
	int	i;

	i = 0;
	while (game()->map->layout[i])
		i++;
	return (i);
}

static bool	is_map_cell(t_pos cell)
{
	if (cell.x < 0 || cell.y < 0 || cell.x > get_map_width(cell.y) || cell.y > get_map_height())
		return (false);
	return (true);
}

//static bool	diagonal_helper(t_pos curr_pos, t_diagonal diagonal)
//{
//	printf("right %c bottom %c\n", game()->map->layout[(int)curr_pos.y][(int)(curr_pos.x + MOVEMENTSPEED)], game()->map->layout[(int)(curr_pos.y + MOVEMENTSPEED)][(int)curr_pos.x]);
//	if (diagonal == BR && game()->map->layout[(int)curr_pos.y][(int)(curr_pos.x + MOVEMENTSPEED)] == '1' && game()->map->layout[(int)(curr_pos.y + MOVEMENTSPEED)][(int)curr_pos.x] == '1')
//		return (true);
//	return (false);
//}

/*
	top row : layout[(int)curr_pos.y - 1][(int)curr_pos.x - 1],layout[(int)curr_pos.y - 1][(int)curr_pos.x],layout[(int)curr_pos.y - 1][(int)curr_pos.x + 1]
	mid row : layout[(int)curr_pos.y][(int)curr_pos.x - 1]	   ,layout[(int)curr_pos.y][(int)curr_pos.x]	,layout[(int)curr_pos.y][(int)curr_pos.x + 1]
	bot row : layout[(int)curr_pos.y + 1][(int)curr_pos.x - 1],layout[(int)curr_pos.y + 1][(int)curr_pos.x],layout[(int)curr_pos.y + 1][(int)curr_pos.x + 1]

							y x
	diagonal top left 	:	- -
	diagonal top right	:	- +
	diagonal bot left	:	+ -
	diagonal bot right	:	+ +
*/


//static bool	check_diagonal()
//{
//	t_pos	curr_dir;
//	t_pos	curr_pos;
//
//	curr_pos = convert_to_map(game()->player.pos);
//	curr_dir = game()->player.dir;
//	if (curr_dir.y < 0 && curr_dir.x < 0) // TL
//		return (diagonal_helper(curr_pos, TL));
//	//else if (curr_dir.y < 0 && curr_dir.x > 0)// TR
//	//	return (diagonal_helper(TR));
//	//else if (curr_dir.y > 0 && curr_dir.x < 0)// BL
//	//	return (diagonal_helper(BL));
//	else if (curr_dir.y > 0 && curr_dir.x > 0)// BR
//		return (diagonal_helper(curr_pos, BR));
//	return (false);
//}

int	check_move(t_pos move)
{
	t_pos	next;
	int moved;

	next = convert_to_map(move);
	moved = 0;
	if (!is_map_cell(next) || is_wall(game()->map->layout[(int)next.y][(int)next.x]))
		return (moved);	
	game()->player.pos = move;
	return (++moved);
}
