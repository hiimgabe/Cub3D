/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmagalha <pmagalha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 14:47:52 by pmagalha          #+#    #+#             */
/*   Updated: 2024/07/05 15:16:49 by pmagalha         ###   ########.fr       */
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