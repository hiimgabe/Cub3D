/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_conditions_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamoreir <gamoreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 12:44:42 by gabe              #+#    #+#             */
/*   Updated: 2024/10/31 16:20:54 by gamoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	invalid_characters(char *line)
{
	int	i;

	i = 0;
	if (!line)
		return (0);
	while (line[i])
	{
		if (line[i] != ' ' && line[i] != '1' && line[i] != '0'
			&& line[i] != 'N' && line[i] != 'S' && line[i] != 'W'
			&& line[i] != 'E' && line[i] != '\n')
			return (0);
		i++;
	}
	return (1);
}
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

bool	invalid_space(int curr, int line_nb)
{
	if (line_nb == 0)
		return (top_wall(curr));
	else
		return (bottom_wall(curr, line_nb));
}

int	top_bottom_walls(char *line, int line_nb)
{
	int	i;

	i = -1;
	(void)line_nb;
	if (!line)
		return (error_exit(ERR_EMPTYMAP, NULL), 0);
	while (line[++i])
	{
		if (line[i] != '1' && invalid_space(i, line_nb))
			return (0);
	}
	return (1);
}

int	player_check(char **map)
{
	int	i;
	int	j;
	int	player;

	i = -1;
	player = 0;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
			if (map[i][j] == 'N' || map[i][j] == 'S'
				|| map[i][j] == 'E' || map[i][j] == 'W')
				player++;
	}
	if (player != 1)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}