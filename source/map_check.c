/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamoreir <gamoreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 10:00:33 by pmagalha          #+#    #+#             */
/*   Updated: 2024/11/09 11:39:30 by gamoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	valid_map(char *file)
{
	game()->map->layout = get_map(file);
	if (!game()->map->layout)
		return (error_exit(ERR_INVMAPF, NULL), 1);
	if (map_conditions(game()->map->layout))
		return (error_exit(ERR_INVMAPF, NULL), 1);
	return (0);
}
