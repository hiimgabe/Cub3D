/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmagalha <pmagalha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 10:00:33 by pmagalha          #+#    #+#             */
/*   Updated: 2024/07/10 13:07:32 by pmagalha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int map_lines(char *file)
{
    int     fd;
    int     lines;
    char    *line;

	line = NULL;
    fd = open(file, O_RDONLY);
    if (fd < 0)
        return 0;
    
    lines = 0;
    while (get_next_line(fd) > 0)
    {
        free(line);
        lines++;
    }
    free(line);
    close(fd);
    return lines;
}

char *copy_map_line(char *line, int length)
{
    char *new_line = ft_strndup(line, length);
    return (new_line);
}

char **save_map(char **map, int fd)
{
    int     i;
    char    *line;

    line = get_next_line(fd);
    i = 0;
    while (line)
    {
        if (line[0] != '\0' && line[0] != '\n')
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
    int i = 0;

    while (layout[i])
    {
        printf("%s", layout[i]);
        i++;
    }
}

int valid_map(t_game *game, char *file)
{
    game->map->layout = get_map(file);
    if (!game->map->layout)
    {
        ft_putstr_fd("Error: invalid map.\n", 2);
        return (0);
    }
	if (!map_conditions(game->map->layout))
		print_map(game->map->layout);
	else
		ft_putstr_fd("Error: map is not ok.\n", 2);
    return (1);
}
