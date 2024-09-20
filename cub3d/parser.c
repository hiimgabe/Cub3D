/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabe <gabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 14:47:52 by pmagalha          #+#    #+#             */
/*   Updated: 2024/09/20 15:26:01 by gabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int file_check(char *file, char *ext, int fd)
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
		return (map_error(file), EXIT_FAILURE);
	if (fd < 0)
		return (file_error(fd), EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

static int	textures_validation(char *map)
{
	int		fd;
	char	*line;

	fd = open(map, O_RDONLY);
	if (fd < 0)
		return (error_exit("Invalid map file.\n"), EXIT_FAILURE);
	line = get_next_line(fd);
	while (line)
	{
		parse_map_textures(line);
		if (line)
			free(line);
		if (check_order())
			return (error_exit("Make sure textures and colors exist and are in the correct order.\nTextures order: SO->NO->WE->EA->F->C\n"), EXIT_FAILURE);
		line = get_next_line(fd);
	}
	if (check_xpm() || check_colors())
		return (error_exit("Make sure textures files and colors exist in the provided file and are in the correct format(XPM for textures and RGB for colors).\n"), EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	parse_data(char *argv)
{
 	if (textures_validation(argv))
		return (error_exit("Invalid textures.\n"), EXIT_FAILURE);
	printf("%s\n%s\n%s\n%s\n%s\n%s\n", game()->map->so, game()->map->no, game()->map->we, game()->map->ea, game()->map->f, game()->map->c);
	if (valid_map(argv))
		return (error_exit("Map validation error\n"), EXIT_FAILURE);
	return (EXIT_SUCCESS);
}