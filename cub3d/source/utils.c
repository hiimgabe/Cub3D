/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamoreir <gamoreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 13:16:57 by gabe              #+#    #+#             */
/*   Updated: 2024/10/16 18:53:16 by gamoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

long	get_time()
{
	struct timeval	curr_time;

	gettimeofday(&curr_time, NULL);
	return ((curr_time.tv_sec * 1000) + (curr_time.tv_usec / 1000));
}

int is_space(char c)
{
	return (c == 32 || (c >= 9 && c <= 13));
}

int is_number(char c)
{
	return (c >= 48 && c <= 57);
}

int check_order()
{
	if ((game()->map->no && !game()->map->so) || (game()->map->we && !game()->map->no) || (game()->map->ea && !game()->map->we) || (game()->map->f && !game()->map->ea) || (game()->map->c && !game()->map->f))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int is_valid_xpm_file(char *xpm)
{
	int len;
	char *extention;

	if (xpm[0] != '.')
		return (EXIT_FAILURE);
	len = ft_strlen(xpm);
	extention = ft_substr(xpm, len - 4, 4);
	if (!strncmp(extention, ".xpm", 4))
	{
		free(extention);
		return (EXIT_SUCCESS);
	}
	free(extention);
	return (EXIT_FAILURE);
}

int check_xpm()
{
	if (is_valid_xpm_file(game()->map->so) || is_valid_xpm_file(game()->map->no) || is_valid_xpm_file(game()->map->we) || is_valid_xpm_file(game()->map->ea))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int check_rgb(char **colors)
{
	int color[3];

	color[0] = ft_atoi(colors[0]);
	color[1] = ft_atoi(colors[1]);
	color[2] = ft_atoi(colors[2]);
	if (!(color[0] >= 0 && color[0] <= 255) || !(color[1] >= 0 && color[1] <= 255) || !(color[2] >= 0 && color[2] <= 255))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int check_colors()
{
	char **colors;

	if (!game()->map->f || !game()->map->c)
		return (EXIT_FAILURE);
	colors = ft_split(game()->map->f, ',');
	if (check_rgb(colors))
	{
		free_matrix(colors);
		return (EXIT_FAILURE);
	}
	free_matrix(colors);
	colors = ft_split(game()->map->c, ',');
	if (check_rgb(colors))
	{
		free_matrix(colors);
		return (EXIT_FAILURE);
	}
	free_matrix(colors);
	return (EXIT_SUCCESS);
}

int get_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void free_matrix(char **matrix)
{
	int i;

	i = -1;
	while (matrix[++i])
		free(matrix[i]);
	free(matrix);
}

bool	is_floor(char c)
{
	return (c == '0');
}

bool	is_wall(char c)
{
	return (c == '1');
}