/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabe <gabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 13:16:57 by gabe              #+#    #+#             */
/*   Updated: 2024/10/22 14:48:51 by gabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	check_order(void)
{
	if ((game()->map->no && !game()->map->so)
		|| (game()->map->we && !game()->map->no)
		|| (game()->map->ea && !game()->map->we)
		|| (game()->map->f && !game()->map->ea)
		|| (game()->map->c && !game()->map->f))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	check_rgb(char **colors)
{
	int	color[3];

	color[0] = ft_atoi(colors[0]);
	color[1] = ft_atoi(colors[1]);
	color[2] = ft_atoi(colors[2]);
	if (!(color[0] >= 0 && color[0] <= 255)
		|| !(color[1] >= 0 && color[1] <= 255)
		|| !(color[2] >= 0 && color[2] <= 255))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	check_colors(void)
{
	char	**colors;

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

int	get_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void	free_matrix(char **matrix)
{
	int	i;

	i = -1;
	while (matrix[++i])
		free(matrix[i]);
	free(matrix);
}
