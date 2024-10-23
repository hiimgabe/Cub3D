/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabe <gabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 14:47:52 by pmagalha          #+#    #+#             */
/*   Updated: 2024/10/23 21:33:57 by gabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static int	textures_validation(char *map)
{
	int		fd;
	char	*line;

	fd = open(map, O_RDONLY);
	if (fd < 0)
		return (error_exit(ERR_INVMAPF, NULL), EXIT_FAILURE);
	line = get_next_line(fd);
	while (line)
	{
		parse_map_textures(line);
		if (line)
			free(line);
		line = get_next_line(fd);
	}
	if (check_xpm() || check_colors())
		return (error_exit(ERR_TXTCLRFMT, NULL), EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

static void	check_file(char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		error_exit(ERR_FILENTFD, file);
}

static void	check_elements(void)
{
	if (!game()->map->no || !game()->map->so
		|| !game()->map->we || !game()->map->ea
		|| !game()->map->c || !game()->map->f)
		error_exit(ERR_MISSINGTXT, NULL);
	check_file(game()->map->no);
	check_file(game()->map->so);
	check_file(game()->map->we);
	check_file(game()->map->ea);
}

static void	replace_mapspace(void)
{
	int		i;
	int		j;
	char	**map;

	i = -1;
	map = game()->map->layout;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
			if (map[i][j] == ' ')
				map[i][j] = '1';
	}
}

int	parse_data(char *argv)
{
	if (textures_validation(argv))
		return (error_exit(ERR_TXTINV, NULL), EXIT_FAILURE);
	if (valid_map(argv))
		return (error_exit(ERR_MAPVALID, NULL), EXIT_FAILURE);
	check_elements();
	replace_mapspace();
	check_map(game()->map->layout);
	return (EXIT_SUCCESS);
}
/*
//int		order;
//order = 0;
//if (check_order())
//	order++;
//if (order != 0)
//	return (error_exit(ERR_TXTCLRORD, NULL), EXIT_FAILURE);
*/