/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabe <gabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 10:15:19 by pmagalha          #+#    #+#             */
/*   Updated: 2024/07/10 15:34:18 by gabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# define SYNTAX 

/*------------- Libraries ---------------*/

# include "libs/libft/libft.h"
# include <stdbool.h>
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <signal.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include <fcntl.h>
# include "libs/minilibx-linux/mlx.h"


/*------------- Structures ---------------*/

typedef struct	s_map
{
	char	**layout;
	int		map_width;
	int		map_height;
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	char	*f;
	char	*c;
}				t_map;

typedef struct	s_game {
	t_map	*map;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_game;

/*------------- Error functions ---------------*/

t_game	*game(void);

int	map_error(char *file);
int	file_error(int fd);
int	check_extension(char *str);
int	parse_data(char *argv);
void	init_game(void);
void	start_game();
void	error_exit(char *error);

#endif