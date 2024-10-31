/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walls_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamoreir <gamoreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 17:38:59 by gamoreir          #+#    #+#             */
/*   Updated: 2024/10/31 17:42:57 by gamoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

bool	top_wall(int curr)
{
	char	**map;
	int		i;

	map = game()->map->layout;
	i = -1;
	while (map[++i])
	{
		if (map[i][curr] == '1')
			return (false);
		else if (map[i][curr] != '1' && !is_space(map[i][curr]))
			return (true);
	}
	return (true);
}

bool	bottom_wall(int curr, int line_nb)
{
	char	**map;
	int		i;

	map = game()->map->layout;
	i = -1;
	i = line_nb + 1;
	while (map[--i])
	{
		if (map[i][curr] == '1')
			return (false);
		else if (map[i][curr] != '1' && !is_space(map[i][curr]))
			return (true);
	}
	return (true);
}

bool	is_lastwall(char *line)
{
	int	i;

	i = -1;
	while (line[++i])
	{
		if (line[i] == '1' || line[i] == '0'
			|| line[i] == 'N' || line[i] == 'S'
			|| line[i] == 'W' || line[i] == 'E')
			return (false);
	}
	return (true);
}

bool	is_onlyspaces(char *line)
{
	int	i;

	i = -1;
	if (!line)
		return (false);
	while (line[++i])
		if (!is_space(line[i]))
			return (false);
	return (true);
}
