/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabe <gabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 10:15:19 by pmagalha          #+#    #+#             */
/*   Updated: 2024/10/04 15:24:58 by gabe             ###   ########.fr       */
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
# include <math.h>
# include "libs/minilibx-linux/mlx.h"

/*MACROS*/
#define	MAP_POS		50
#define	TILE_SIZE	10
#define	RENDER_DIST	10
#define	SCREEN_W		800
#define	SCREEN_H		800

/*------------- Structures ---------------*/

typedef enum {
	NORTH,
	SOUTH,
	WEST,
	EAST
} compass;

typedef struct	s_pos
{
	double	x;
	double	y;
}				t_pos;

typedef struct	s_map
{
	char	**layout;
	int		map_height;
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	char	*f;
	char	*c;
}				t_map;

typedef	struct s_img
{
	void	*img;
	int		*addr;
	int		bpp;
	int		size_line;
	int		endian;
}				t_img;

typedef struct s_texture_info
{
	int	size;
	int	c;
	int	f;
	int	index;
	int	x;
	int	y;
	double	step;
	double	pos;
}				t_texture_info;

typedef struct	s_ray
{
	t_pos	pos;
	t_pos	dir;
	t_pos	delta_dist;
	t_pos	side_dist;
	t_pos	step;
	double	perp_wall_dist;
	double	wall_x;
	int		line_height;
	int		start;
	int		end;
	int		side;
}				t_ray;

typedef struct	s_player
{
	t_pos	pos;
	t_pos	dir;
	t_pos	cam;
	bool	moving;
	char	compass;
}				t_player;

typedef struct	s_game
{
	t_map			*map;
	t_texture_info	*texture_info;
	t_img			screen_buffer;
	t_player		player;
	void			*mlx;
	void			*mlx_win;
	void			*img;
	int				**textures;
	int				screenSizex;
	int				screenSizey;
}				t_game;

/*------------- Init functions ---------------*/

t_game	*game(void);
t_map	*init_map(t_map *map);
void	init_game(void);
void	init_mlx();
void	load_textures();

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
void	parse_map_textures(char *line);

/*------------- Extention validation functions ---------------*/


/*------------- Free functions ---------------*/
void free_map(t_map *map);
void free_game();

/*------------- Debugging functions ---------------*/
void print_map(char **layout);
int	parse_data(char *argv);
void	init_game(void);
void	error_exit(char *error);

/*----------------- utils -------------------*/
int	is_space(char c);
int	check_xpm();
int	check_order();
int	check_colors();
int	get_trgb(int t, int r, int g, int b);
void	free_matrix(char **matrix);
bool	is_wall(char c);
void	start_game();

/*------------------input.c------------------*/

int	handle_input(int key);


/*------------------render.c------------------*/
int		render_game(void);
void	render_pixel(t_pos pos, int color);

/*-------------------player.c----------------*/
void	load_player();

/*-------------------raycast.c-----------------*/
void	raycast();

/*----------------utils_pos.c-------------------*/
t_pos	convert_to_screen(t_pos pos);
t_pos	convert_to_map(t_pos screen_pos);

/*texture utils*/

int	shader(double wall_dist, int color);
int	shader_floor(int dist, int color);
int	shader_ceiling(int dist, int color);

#endif