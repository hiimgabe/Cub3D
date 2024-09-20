/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabe <gabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 10:00:33 by pmagalha          #+#    #+#             */
/*   Updated: 2024/09/20 15:25:07 by gabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int map_lines(char *file)
{
    int     fd;
    int     lines;
    char    *line;

    fd = open(file, O_RDONLY);
    if (fd < 0)
        return (0);
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

char *copy_map_line(char *line, int length)
{
    char *new_line;
    
    new_line = ft_strndup(line, length);
    return (new_line);
}

bool    map_start(char *line)
{
    int i;

    i = 0;
    while (line[i] == ' ')
        i++;
    if (line[i] == '1')
        return (true);
    return (false);
}

char **save_map(char **map, int fd)
{
    int     i;
    char    *line;
    bool    start;

    start = false;
    line = get_next_line(fd);
    i = 0;
    while (line)
    {
        if (!start && map_start(line))
            start = true;
        if (start && line[0] != '\0' && line[0] != '\n')
            map[i++] = copy_map_line(line, ft_strlen(line));
        free(line);
        line = get_next_line(fd);
    }
    free(line);
    return map;
}

char	**get_map(char *file)
{
	int		lines;
	int		fd;
	char	**map;

	lines = map_lines(file);
	if (lines <= 0)
		return (NULL);
	map = ft_calloc(lines + 1, sizeof(char *));
	if (!map)
		return (NULL);
	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		free(map);
		return (NULL);
	}
	if (!save_map(map, fd))
	{
		free(map);
		return (NULL);
	}
	close(fd);
	return (map);
}

void print_map(char **layout)
{
    int i = -1;

    while (layout[++i] != NULL)
        printf("%s", layout[i]);
    printf("\n");
}

int valid_map(char *file)
{
    game()->map->layout = get_map(file);
    if (!game()->map->layout)
    {
        ft_putstr_fd("Error: invalid map.\n", 2);
        return (1);
    }
	if (!map_conditions(game()->map->layout))
		print_map(game()->map->layout);
	else
		return (ft_putstr_fd("Error: map is not ok.\n", 2), 1);
    return (0);
}
