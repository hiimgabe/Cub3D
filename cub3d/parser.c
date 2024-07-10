/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabe <gabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 14:47:52 by pmagalha          #+#    #+#             */
/*   Updated: 2024/07/10 18:28:13 by gabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//Here we should make the map parsing and validation
//I chose to ignore the first lines with the NSWE orientations for now and just check the map
// This would be working provided ./cub3d received a file with just the map in it


/* static void	map_parsing(char *str)
{
	
}

int	valid_map(char *file, int fd)
{
	char *line;

	fd = open(file, O_RDONLY);
	line = get_next_line(fd);
	
	while (line)
	{
		map_parsing(line);
		if (line)
			free(line);
		line = get_next_line(fd);
	}
	map_check(game()->map);
} */

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

	// Here are the 4 conditions for file check
	// 1 - file extension must be .cub
	// 2 - The dot is right before the "cub"
	// 3 - There cannot be more than 1 dot (so map...cub wont work)
	// 4 - file lenght must be bigger than file extension
	i = file_len - ext_len;
    if (strcmp(file + i, ext) != 0 || (i > 0 && file[i - 1] == '.') 
		|| dot_count != 1 || file_len < ext_len)
		return (map_error(file), 0);
	
	// We make an fd check here since we have enough lines.
	// No need to check the fd again on the map parsing because of this
	if (fd < 0)
		return (file_error(fd), 0);
	
	return (1);
}

char	*trim_line(char *line)
{
	int		i;
	int		len;
	char	*trim;

	i = 0;
	len = ft_strlen(line);
	while (line[i] != '.')
		i++;
	trim = ft_substr(line, i, len - i);
	return (trim);
}

// Not sure if it is supposed to be a certain order but for now the 
// order is SO(0) -> NO(1) -> WE(2) -> EA(3) 
void	fill_texture(char *texture, int index)
{
	if (!texture)
		return ;
	if (index == 0)
		game()->map->so = texture;
	else if (index == 1)
		game()->map->no = texture;
	else if (index == 2)
		game()->map->we = texture;
	else if (index == 3)
		game()->map->ea = texture;
}

static int	textures_validation(char *map)
{
	int		fd;
	int		xpm_cnt;
	char	*line;
	char	*extension;

	fd = open(map, O_RDONLY);
	xpm_cnt = -1;
	while(1)
	{
		line = get_next_line(fd);
		line = trim_line(line);
		extension = ft_substr(line, ft_strlen(line) - 5, 4);
		if (ft_strncmp(".xpm", extension, 4))
			return (error_exit("Wrong file extention.\n"), 1);
		else
			xpm_cnt++;
		fill_texture(line, xpm_cnt);
		if (xpm_cnt == 3)
			break ;
	}
	return (0);
}

int	parse_data(char *argv)
{
	if (textures_validation(argv))
		return (error_exit("Textures validation error.\n"), 1);
	//if (map_validation(argv))
	//	return (error_exit("Map validation error"), 1);
	return (0);
}