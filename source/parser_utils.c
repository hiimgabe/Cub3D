/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamoreir <gamoreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 10:19:16 by gabe              #+#    #+#             */
/*   Updated: 2024/11/09 11:10:51 by gamoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

bool	is_valid_line(char *line)
{
	if (!is_space(line[0]) && line[0] != 'N'
		&& line[0] != 'S' && line[0] != 'E'
		&& line[0] != 'W' && line[0] != 'F'
		&& line[0] != 'C' && line[0] != '1')
		return (false);
	return (true);
}

bool	dup_text(char *trim)
{
	if (!ft_strncmp(trim, "NO", 2) && game()->map->no != 0)
		return (true);
	if (!ft_strncmp(trim, "SO", 2) && game()->map->so != 0)
		return (true);
	if (!ft_strncmp(trim, "EA", 2) && game()->map->ea != 0)
		return (true);
	if (!ft_strncmp(trim, "WE", 2) && game()->map->we != 0)
		return (true);
	if (!ft_strncmp(trim, "F", 1) && game()->map->f != 0)
		return (true);
	if (!ft_strncmp(trim, "C", 1) && game()->map->c != 0)
		return (true);
	return (false);
}

int	file_check(char *file)
{
	size_t	i;
	int		fd;

	i = 0;
	if (ft_strncmp(&file[i], ".cub", 4))
		return (error_exit(ERR_INVEXT, file), EXIT_FAILURE);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (error_exit(ERR_FILENTFD, NULL), EXIT_FAILURE);
	while (i < ft_strlen(file) - 4)
		i++;
	close(fd);
	return (EXIT_SUCCESS);
}
