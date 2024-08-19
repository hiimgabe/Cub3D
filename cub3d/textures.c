/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabe <gabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 19:49:30 by gabe              #+#    #+#             */
/*   Updated: 2024/08/19 15:35:01 by gabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	load_colors(char *str, char c_f)
{
	char	**colors;
	int		*color;
	int		red;
	int		green;
	int		blue;
	
	if (c_f == 'c')
		color = &game()->texture_info->c;
	else
		color = &game()->texture_info->f;
	colors = ft_split(str, ',');
	red = ft_atoi(colors[0]);
	green = ft_atoi(colors[1]);
	blue = ft_atoi(colors[2]);
	*color = get_trgb(0 , red, green, blue);
	free_matrix(colors);
}

void	load_textures()
{
	load_colors(game()->map->c, 'c');
	load_colors(game()->map->f, 'f');

	printf("%s\n%s\n", game()->map->c, game()->map->f);
	printf("%d\n%d\n", game()->texture_info->c, game()->texture_info->f);
}