/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabe <gabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 14:47:52 by pmagalha          #+#    #+#             */
/*   Updated: 2024/10/22 14:46:07 by gabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	file_check(char *file, char *ext, int fd)
{
	size_t	i;
	size_t	ext_len;
	size_t	file_len;
	size_t	dot_count;

	dot_count = 0;
	ext_len = ft_strlen(ext);
	file_len = ft_strlen(file);
	i = file_len - ext_len;
	fd = open(file, O_RDONLY);
	while (i > 0)
	{
		if (file[i] == '.')
			dot_count++;
		i--;
	}
	i = file_len - ext_len;
	if (strcmp(file + i, ext) != 0 || (i > 0 && file[i - 1] == '.')
		|| dot_count != 1 || file_len < ext_len)
		return (error_exit(ERR_INVMAPF, file), EXIT_FAILURE);
	if (fd < 0)
		return (error_exit(ERR_FILENTFD, NULL), EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

static int	textures_validation(char *map)
{
	int		fd;
	char	*line;
	int		order;

	order = 0;
	fd = open(map, O_RDONLY);
	if (fd < 0)
		return (error_exit(ERR_INVMAPF, NULL), EXIT_FAILURE);
	line = get_next_line(fd);
	while (line)
	{
		parse_map_textures(line);
		if (line)
			free(line);
		if (check_order())
			order++;
		line = get_next_line(fd);
	}
	if (order != 0)
		return (error_exit(ERR_TXTCLRORD, NULL), EXIT_FAILURE);
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

int	parse_data(char *argv)
{
	if (textures_validation(argv))
		return (error_exit(ERR_TXTINV, NULL), EXIT_FAILURE);
	if (valid_map(argv))
		return (error_exit(ERR_MAPVALID, NULL), EXIT_FAILURE);
	check_elements();
	return (EXIT_SUCCESS);
}
