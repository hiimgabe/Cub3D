/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabe <gabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 15:34:26 by gabe              #+#    #+#             */
/*   Updated: 2024/10/22 19:33:57 by gabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

size_t	matrix_len(char **matrix)
{
	size_t	i;

	i = 0;
	while (matrix[i])
		i++;
	return (i);
}

void	print_map(t_pos err_pos)
{
	int	i;
	int	j;

	i = -1;
	printf("x %f y %f\n", err_pos.x, err_pos.y);
	while (game()->map->layout[++i])
	{
		j = -1;
		while (game()->map->layout[i][++j])
		{
			if (i == err_pos.x && j == err_pos.y)
				printf("%s%c%s", RED, game()->map->layout[i][j], RESET);
			else
				printf("%c", game()->map->layout[i][j]);
		}
	}
	printf("\n");
}

static bool	only_walls(char *line)
{
	size_t	i;

	i = -1;
	while (line[++i])
	{
		if (line[i] != '1' && line[i] != ' ' && line[i] != '\n')
			return (false);
	}
	return (true);
}

static bool	check_surround(char *top, char *curr, char *down, int i)
{
	size_t	j;

	j = -1;
	while (curr[++j] && curr[i] != 10)
	{
		if (curr[0] != '1' && (curr[ft_strlen(curr) - 1] != '1'))
			return (false);
		if (top && ft_strlen(curr) > ft_strlen(top) && j > ft_strlen(top) - 1 && curr[j] != '1')
			return (false);
		if (down && ft_strlen(curr) > ft_strlen(down) && j > ft_strlen(down) - 1 && curr[j] != '1')
			return (false);
	}
	return (true);
}

static bool	is_surrounded(char **map, size_t i)
{
	char	*top;
	char	*curr;
	char	*down;
	
	top = NULL;
	curr = map[i];
	down = NULL;
	if (i > 0)
		top = map[i - 1];
	if (i < matrix_len(map))
		down = map[i + 1];
	return (check_surround(top, curr, down, i));
}

void	check_map(char **map)
{
	size_t	i;

	i = -1;
	if (map[0] == NULL)
		error_exit(ERR_INVMAPF, NULL);
	while (map[++i])
	{
		if (!only_walls(map[i]) && (i == 0 || (int)i == game()->map->map_height))
			error_exit(ERR_MAPWALLS, NULL);
		if (map[i][0] == '\0')
			error_exit(ERR_MAPWALLE, NULL);
		if (!is_surrounded(map, i))
			error_exit(ERR_MAPSURR, NULL);
	}
	//print_map((t_pos){1, 1});
}