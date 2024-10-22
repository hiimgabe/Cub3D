/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_conditions_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabe <gabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 12:44:42 by gabe              #+#    #+#             */
/*   Updated: 2024/10/22 19:25:03 by gabe             ###   ########.fr       */
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

int	top_bottom_walls(char *line)
{
	int	i;

	i = 0;
	if (!line)
		return (error_exit(ERR_EMPTYMAP, NULL), 0);
	while (line[i] && line[i] != '\n')
	{
		if (line[i] != '1' && line[i] != ' ')
			return (0);
		i++;
	}
	return (1);
}

int	invalid_walls(char **layout)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!game()->map->layout)
		return (0);
	if (i > 1 && ft_strlen(layout[i]) > ft_strlen(layout[i - 1])
		&& j >= ft_strlen(layout[i - 1]) && layout[i][j] && layout[i][j] != '1')
		return (0);
	if (layout[i + 1] != NULL && ft_strlen(layout[i]) > ft_strlen(layout[i + 1])
		&& j >= ft_strlen(layout[i + 1]) && layout[i][j] && layout[i][j] != '1')
		return (0);
	if (i == 0 || layout[i + 1] == NULL)
		if (layout[i][j] != '1' && layout[i][j] != ' ')
			return (0);
	return (1);
}

int	invalid_borders(char *line)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (!line)
		return (0);
	while (line[i] == ' ')
		i++;
	if (line[i] != '1')
		return (error_exit(ERR_MAPBORD, NULL), 0);
	j = ft_strlen(line) - 1;
	while (line[j] == ' ')
		j--;
	if (line[j] != '1')
		return (error_exit(ERR_MAPBORD, NULL), 0);
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
