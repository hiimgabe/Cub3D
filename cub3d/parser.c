/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabe <gabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 14:47:52 by pmagalha          #+#    #+#             */
/*   Updated: 2024/07/09 14:38:30 by gabe             ###   ########.fr       */
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

int	map_validation(char *argv)
{
	if (!file_check(argv, ".cub", 0))
		return (1);
	return (0);
}

void	parse_data(char *argv)
{
	if (map_validation(argv))
		error_exit("ERROR");
}