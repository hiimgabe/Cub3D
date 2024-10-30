/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_conditions_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabe <gabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 12:44:42 by gabe              #+#    #+#             */
/*   Updated: 2024/10/30 18:18:15 by gabe             ###   ########.fr       */
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

bool	invalid_space(int curr, int line_nb)
{
	//print_map(game()->map->layout);
	char	**map;
	int		i;

	map = game()->map->layout;
	if (line_nb == 0)
	{
		i = -1;
		while (map[++i])
		{
			if (map[i][curr] == '1')
				return (true);
		}
	}
	else
	{
		i = line_nb + 1;
		while (map[--i])
		{
			if (map[i][curr] == '1')
				return (false);
		}
		printf("_%c_\n", map[i][curr]);
	}
	printf("=%c=", map[i][curr]);
	return (true);
}

int	top_bottom_walls(char *line, int line_nb)
{
	int	i;


	i = -1;
	(void)line_nb;
	printf("_%d %s\n", line_nb, line);
	if (!line)
		return (error_exit(ERR_EMPTYMAP, NULL), 0);
	while (line[++i])
	{
		printf("_%c_\n", line[i]);
		if (line[i] != '1' && invalid_space(i, line_nb))
			return (0);
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
