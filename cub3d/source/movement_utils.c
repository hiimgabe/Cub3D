/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabe <gabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 11:51:20 by gabe              #+#    #+#             */
/*   Updated: 2024/10/08 15:54:44 by gabe             ###   ########.fr       */
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
