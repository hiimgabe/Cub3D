/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_conditions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabe <gabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 13:07:41 by pmagalha          #+#    #+#             */
/*   Updated: 2024/10/21 15:39:18 by gabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static int	invalid_characters(char *line)
{
	int	i;
	int	player;

	i = 0;
	if (!line)
		return (0);
	while (line[i])
	{
		if (line[i] != ' ' && line[i] != '1' && line[i] != '0'
			&& line[i] != 'N' && line[i] != 'S' && line[i] != 'W' && line[i] != 'E' && line[i] != '\n')
				return (0);
		else if (line[i] == 'N' || line[i] == 'S' || line [i] == 'W' || line[i] == 'E')
			player++;
		i++;
	}
	if (player != 1)
		return (0);
	return (1);
}

static int	top_bottom_walls(char *line)
{
	int	i;

	i = 0;
	if (!line)
		return (ft_putstr_fd("Error: Empty map\n", 2), 0);
	while (line[i] && line[i] != '\n')
    {
        if (line[i] != '1' && line[i] != ' ')
			return (0);
        i++;
    }
	return (1);
}

static int	invalid_walls(char **layout)
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

static int	invalid_borders(char *line)
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
		return (ft_putstr_fd("Error: invalid map borders left side.\n", 2), 0);
	j = ft_strlen(line) - 2;
	while (line[j] == ' ')
		j--;
	if (line[j] != '1')
		return (ft_putstr_fd("Error: invalid map borders right side.\n", 2), 0);
	return (1);
}

int map_conditions(char **layout)
{
    int x;
	
	x = 0;
	if (!game()->map->layout)
		return (0);
	if (!top_bottom_walls(layout[x]))
		return (ft_putstr_fd("Error: invalid top wall elements.\n", 2), 1);
	if (!invalid_walls(layout))
		return (ft_putstr_fd("Error: invalid walls.\n", 2), 1);
    while (layout[x])
    {
        if (!invalid_characters(layout[x]))
            return (ft_putstr_fd("Error: invalid map elements.\n", 2), 1);


        if (!invalid_borders(layout[x]))
            return (ft_putstr_fd("Error: invalid map BORDERS.\n", 2), 1);
        x++;
    }
	x--;
	if (!top_bottom_walls(layout[x]))
		return (ft_putstr_fd("Error: invalid bottom wall elements.\n", 2), 1);
    return (0);
}
