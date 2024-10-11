/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabe <gabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 19:49:30 by gabe              #+#    #+#             */
/*   Updated: 2024/10/08 10:25:00 by gabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

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
/*
	loading textures from their path into their variable
	
	t_img 	img; stores temporary data we need to transfer to buff
	int		*buff; stores our array of int of the image
	
	1st		turn xpm into image using mlx_xpm_file_to_image()
	2nd		get image address <img.addr> by typecasting (int *)mlx_get_data_addr()
	3rd		assign values from img.addr[] to buff[]
*/
static int	*load_texture(char *path)
{
	t_img	img;
	int		*buff;
	int		y;
	int		x;

	y = -1;
	img.img = mlx_xpm_file_to_image(game()->mlx, path, &(game()->texture_info->size), &(game()->texture_info->size));
	if (!img.img)
		error_exit("img.img");
	img.addr = (int *)mlx_get_data_addr(img.img, &img.bpp, &img.size_line, &img.endian);
	buff = ft_calloc(1, sizeof(int) * game()->texture_info->size * game()->texture_info->size);
	if (!buff)
		error_exit("texture buffer error");
	while (++y < game()->texture_info->size)
	{
		x = -1;
		while (++x < game()->texture_info->size)
		{
			buff[y * game()->texture_info->size + x] = img.addr[y * game()->texture_info->size + x];
		}
	}
	mlx_destroy_image(game()->mlx, img.img);
	return (buff);
}

void	load_textures()
{
	load_colors(game()->map->c, 'c');
	load_colors(game()->map->f, 'f');
	game()->textures[NORTH] = load_texture(game()->map->no);
	game()->textures[SOUTH] = load_texture(game()->map->so);
	game()->textures[WEST] = load_texture(game()->map->we);
	game()->textures[EAST] = load_texture(game()->map->ea);
}