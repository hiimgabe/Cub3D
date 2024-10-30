/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_conditions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabe <gabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 13:07:41 by pmagalha          #+#    #+#             */
/*   Updated: 2024/10/30 20:20:44 by gabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	map_conditions(char **layout)
{
	int	x;

	x = -1;
	if (!game()->map->layout)
		return (0);
	if (!top_bottom_walls(layout[0], 0))
		return (error_exit(ERR_MAPWALLS, NULL), 1);
	//if (!invalid_walls(layout))
	//	return (error_exit(ERR_MAPWALLS, NULL), 1);
	while (layout[++x])
	{
		if (!invalid_characters(layout[x]))
			return (error_exit(ERR_MAPELE, NULL), 1);
	}
	if (player_check(layout))
		return (error_exit(ERR_PNOTFND, NULL), 1);
	if (!top_bottom_walls(layout[x - 1], x - 1))
		return (error_exit(ERR_MAPWALLS, NULL), 1);
	return (0);
}
