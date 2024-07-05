/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmagalha <pmagalha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 10:01:43 by pmagalha          #+#    #+#             */
/*   Updated: 2024/07/05 15:30:15 by pmagalha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libs/minilibx-linux/mlx.h"

// Added this so we can call game()->map for example

t_game	*game(void)
{
	static t_game	game;

	return (&game);
}

void	my_mlx_pixel_put(t_game *game, int x, int y, int color)
{
	char	*dst;

	dst = game->addr + (y * game->line_length + x * (game->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int file_check(char *file, char *ext, int fd)
{
	size_t	i;
	size_t	ext_len;
	size_t	file_len;
	size_t	dot_count;

	dot_count = 0;
	ext_len = ft_strlen(ext);
	file_len = ft_strlen(file);
	i = file_len - ext_len;
	fd = open(file, O_RDONLY);
	while (i > 0)
	{
		if (file[i] == '.')
			dot_count++;
		i--;
	}

	// Here are the 4 conditions for file check
	// 1 - file extension must be .cub
	// 2 - The dot is right before the "cub"
	// 3 - There cannot be more than 1 dot (so map...cub wont work)
	// 4 - file lenght must be bigger than file extension
	i = file_len - ext_len;
    if (strcmp(file + i, ext) != 0 || (i > 0 && file[i - 1] == '.') 
		|| dot_count != 1 || file_len < ext_len)
		return (map_error(file), 0);
	
	// We make an fd check here since we have enough lines.
	// No need to check the fd again on the map parsing because of this
	if (fd < 0)
		return (file_error(fd), 0);
	
	return (1);
}

int	main(int argc, char **argv)
{
	int		fd;
	void	*mlx;
	void	*mlx_win;
	t_game	img;

	fd = 0;
	if (argc != 2)
	{
		ft_putstr_fd("Error: no map file provided.\n", 2);
		return (1);
	}
	
// This is where we check the file, which should end in ".cub"
	if (!file_check(argv[1], ".cub", fd))
		return (1);
	
// Here is where we will begin the process of parsing and validating the map
/* 	if (!valid_map(argv[1]), fd)
		return (1); */

// This is just random stuff to create a window if every check is successfull 
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 256, 256, "'Tis a window'");
	img.img = mlx_new_image(mlx, 256, 256);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	my_mlx_pixel_put(&img, 5*5, 5*5, 0x00FF0000);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}