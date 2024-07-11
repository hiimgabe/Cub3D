/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabe <gabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 10:15:19 by pmagalha          #+#    #+#             */
/*   Updated: 2024/07/11 16:33:36 by pmagalha         ###   ########.fr       */
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

/*------------- Init functions ---------------*/

t_game	*game(void);
t_map	*init_map(t_map *map);
void	init_game(void);

/*------------- Parsing functions ---------------*/

int	parse_data(char *argv);
int file_check(char *file, char *ext, int fd);

/*------------- Error functions ---------------*/

t_game	*game(void);

int	map_error(char *file);
int	file_error(int fd);
void	error_exit(char *error);

/*-------- Map validation functions ----------*/

int map_lines(char *file);
char *copy_map_line(char *line, int length);
char **save_map(char **map, int fd);
char	**get_map(char *file);
int valid_map(char *file);
int	map_conditions(char **layout);

/*------------- Extention validation functions ---------------*/

int	check_extension(char *str);

/*------------- Free functions ---------------*/
void free_map(t_map *map);
void free_game();

/*------------- Debugging functions ---------------*/
void print_map(char **layout);
int	check_extension(char *str);
int	parse_data(char *argv);
void	init_game(void);
void	start_game();
void	error_exit(char *error);

#endif