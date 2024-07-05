/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmagalha <pmagalha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 10:01:43 by pmagalha          #+#    #+#             */
/*   Updated: 2024/07/05 14:19:53 by pmagalha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libs/minilibx-linux/mlx.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int file_check(char *file, char *ext)
{
	size_t	i;
	size_t	ext_len;
	size_t	file_len;
	size_t	dot_count;

	dot_count = 0;
	file_len = ft_strlen(file);
	ext_len = ft_strlen(ext);
	i = file_len - ext_len;
	while (i > 0)
	{
		if (file[i] == '.')
			dot_count++;
		i--;
	}
	i = file_len - ext_len;
    if (strcmp(file + i, ext) != 0 || (i > 0 && file[i - 1] == '.') 
		|| dot_count != 1 || file_len < ext_len)
		return (map_error(file), 0);
	return (1);
}

int	main(int argc, char **argv)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;

	if (argc != 2)
	{
		ft_putstr_fd("Error: no map file provided.\n", 2);
		return (1);
	}
	
	if (!file_check(argv[1], ".cub"))
		return (1);
	
/* 	if (!valid_map(argv[1]))
		return (1); */

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 256, 256, "'Tis a window'");
	img.img = mlx_new_image(mlx, 256, 256);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	my_mlx_pixel_put(&img, 5*5, 5*5, 0x00FF0000);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}