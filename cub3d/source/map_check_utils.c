/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamoreir <gamoreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 12:59:02 by gabe              #+#    #+#             */
/*   Updated: 2024/10/24 15:36:44 by gamoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static int	file_lines(char *file)
{
	int		fd;
	int		lines;
	char	*line;

	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		close(fd);
		return (0);
	}
	lines = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		free(line);
		lines++;
	}
	free(line);
	close(fd);
	return (lines);
}

static char	*copy_map_line(char *line, int length)
{
	char	*new_line;

	if (line[ft_strlen(line) - 1] == '1')
		new_line = ft_strndup(line, length);
	else
		new_line = ft_strndup(line, length - 1);
	return (new_line);
}

static bool	map_start(char *line)
{
	int	i;

	i = 0;
	while (line[i] == ' ')
		i++;
	if (line[i] == '1')
		return (true);
	return (false);
}

static char	**save_map(char **map, int fd)
{
	int		i;
	char	*line;
	bool	start;

	start = false;
	line = get_next_line(fd);
	i = 0;
	while (line)
	{
		if (!start && map_start(line))
			start = true;
		if (start && line[0] != '\0')
			map[i++] = copy_map_line(line, ft_strlen(line));
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	return (map);
}

char	**get_map(char *file)
{
	int		lines;
	int		fd;
	char	**map;

	lines = file_lines(file);
	if (lines <= 0)
		return (NULL);
	map = ft_calloc(lines + 1, sizeof(char *));
	if (!map)
		return (NULL);
	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		close(fd);
		free(map);
		return (NULL);
	}
	if (!save_map(map, fd))
	{
		close(fd);
		free(map);
		return (NULL);
	}
	close(fd);
	return (map);
}
