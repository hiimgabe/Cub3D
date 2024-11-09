/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamoreir <gamoreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 14:47:52 by pmagalha          #+#    #+#             */
/*   Updated: 2024/11/09 10:51:51 by gamoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static int	textures_validation(char *map)
{
	int		fd;
	int		exit_value;
	char	*line;

	fd = open(map, O_RDONLY);
	exit_value = 0;
	if (fd < 0)
		return (error_exit(ERR_INVMAPF, NULL), EXIT_FAILURE);
	line = get_next_line(fd);
	if (!line)
		error_exit(ERR_EMPTYMAP, NULL);
	while (line)
	{
		if (parse_map_textures(line) || !is_valid_line(line))
			exit_value = 1;
		if (line)
			free(line);
		line = get_next_line(fd);
	}
	close(fd);
	if (check_xpm() || check_colors())
		return (error_exit(ERR_TXTCLRFMT, NULL), EXIT_FAILURE);
	return (exit_value);
}

static void	check_file(char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		error_exit(ERR_FILENTFD, file);
	close(fd);
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
	check_map(game()->map->layout);
	replace_mapspace();
	return (EXIT_SUCCESS);
}
