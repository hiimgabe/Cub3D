/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabe <gabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 13:16:57 by gabe              #+#    #+#             */
/*   Updated: 2024/08/06 15:21:14 by gabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_space(char c)
{
	return (c == 32 || (c >= 9 && c <= 13));
}

int	is_number(char c)
{
	return (c >= 48 && c <= 57);
}

int	check_order()
{
	if ((game()->map->no && !game()->map->so)
		|| (game()->map->we && !game()->map->no)
		|| (game()->map->ea && !game()->map->we)
		|| (game()->map->f && !game()->map->ea)
		|| (game()->map->c && !game()->map->f))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	is_valid_xpm_file(char *xpm)
{
	int		len;
	char	*extention;
	
	if (xpm[0] != '.')
		return (EXIT_FAILURE);
	len = ft_strlen(xpm);
	extention = ft_substr(xpm, len - 4, 4);
	if (!strncmp(extention, ".xpm", 4))
	{
		free(extention);
		return (EXIT_SUCCESS);
	}
	free (extention);
	return (EXIT_FAILURE);
}

int	check_xpm()
{
	if (is_valid_xpm_file(game()->map->so)
		|| is_valid_xpm_file(game()->map->no)
		|| is_valid_xpm_file(game()->map->we)
		|| is_valid_xpm_file(game()->map->ea))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	check_rgb(char **colors)
{
	int		color[3];
	
	color[0] = ft_atoi(colors[0]);
	color[1] = ft_atoi(colors[1]);
	color[2] = ft_atoi(colors[2]);
	if (!(color[0] >= 0 && color[0] <= 255)
		|| !(color[1] >= 0 && color[1] <= 255)
		|| !(color[2] >= 0 && color[2] <= 255))
			return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	check_colors()
{
	char	**colors;
	
	if (!game()->map->f || !game()->map->c)
		return (EXIT_FAILURE);
	colors = ft_split(game()->map->f, ',');
	if (check_rgb(colors))
		return (free(colors), EXIT_FAILURE);
	free(colors);
	colors = ft_split(game()->map->c, ',');
	if (check_rgb(colors))
		return (free(colors), EXIT_FAILURE);
	free(colors);
	return (EXIT_SUCCESS);
}
