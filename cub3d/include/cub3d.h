/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabe <gabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 10:15:19 by pmagalha          #+#    #+#             */
/*   Updated: 2024/10/29 19:21:49 by gabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# define SYNTAX 

/*------------- Libraries ---------------*/

# include "../include/libft/libft.h"
# include "../include/minilibx-linux/mlx.h"
# include <sys/time.h>
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

# define MAP_POS			50
# define TILE_SIZE		10
# define RENDER_DIST		20
# define SCREEN_W		800
# define SCREEN_H		800
# define MOVEMENTSPEED	0.250
# define ROTSPEED		0.025
# define MOUSEWRAP		15
# define MINIMAP_W		0x202060
# define MINIMAP_F		0x5BC8AF
# define MINIMAP_P		0xFF00FF
# define RESET	"\033[0m"
# define RED		"\033[38;5;196m"
# define GREEN	"\033[38;5;47m"
# define YELLOW	"\033[38;5;226m"
# define BLUE	"\033[0;34m"
# define PURPLE	"\033[38;5;93m"
# define CYAN	"\033[1;36m"
# define WHITE	"\033[37m"
# define ERR_TXTCLRFMT	"Error: Make sure to use rgb colors and xpm textures.\n"
# define ERR_TXTINV		"Error: Invalid textures.\n"
# define ERR_MISSINGTXT	"Error: Missing textures.\n"
# define ERR_INVMAPF		"Error: Invalid map file.\n"
# define ERR_FILENTFD	"Error: File not found\n"
# define ERR_MAPVALID	"Error: Map validation error\n"
# define ERR_STRUCTINIT	"Error: Failed to init map struct.\n"
# define ERR_TXTINFO		"Error: Failed to init texture info struct.\n"
# define ERR_MLXINIT		"Error: Failed to init mlx.\n"
# define ERR_MLXWIN		"Error: Failed to init mlx win.\n"
# define ERR_FILETOIMG	"Error: Failed to convert file to img.\n"
# define ERR_TXTBUFF		"Error: Failed to init texture buffer.\n"
# define ERR_NOMAP		"Error: Please provide a map file.\n"
# define ERR_MAPLAYOUT	"Error: Invalid map layout.\n"
# define ERR_EMPTYMAP	"Error: Map is empty.\n"
# define ERR_MAPBORD		"Error: Invalid map borders.\n"
# define ERR_MAPWALLS	"Error: Invalid map walls.\n"
# define ERR_MAPELE		"Error: Invalid map elements.\n"
# define ERR_PNOTFND		"Error: Invalid Player.\n"
# define ERR_MAPWALLE	"Error: Empty line inside map.\n"
# define ERR_MAPSURR	"Error: Map isn't surrounded by walls.\n"
# define ERR_INVEXT		"Error: Invalid Extention"

typedef enum e_diagonal
{
	TL,
	TR,
	BL,
	BR
}	t_diagonal;

typedef enum e_rotation
{
	RIGHT,
	LEFT
}	t_rotation;

typedef enum e_compass
{
	NORTH,
	SOUTH,
	WEST,
	EAST
}	t_compass;

typedef struct s_pos
{
	double	x;
	double	y;
}				t_pos;

typedef struct s_map
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

typedef struct s_img
{
	void	*img;
	int		*addr;
	int		bpp;
	int		size_line;
	int		endian;
}				t_img;

typedef struct s_texture_info
{
	int		size;
	int		index;
	int		c;
	int		f;
	int		x;
	int		y;
	double	step;
	double	pos;
}				t_texture_info;

typedef struct s_ray
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

typedef struct s_player
{
	t_pos	pos;
	t_pos	dir;
	t_pos	cam;
	char	compass;
	bool	minimap;
	bool	fps;
	int		y;
	int		x;
	int		moving;
	int		rotate;
}				t_player;

typedef struct s_game
{
	t_map			*map;
	t_texture_info	*texture_info;
	t_img			screen_buffer;
	t_player		player;
	void			*mlx;
	void			*mlx_win;
	void			*img;
	int				**textures;
}				t_game;

t_game	*game(void);
t_pos	convert_to_screen(t_pos pos);
t_pos	convert_to_map(t_pos screen_pos);
void	init_mlx(void);
void	init_game(void);
void	load_textures(void);
void	load_player(void);
void	free_game(void);
void	exit_free(void);
void	start_game(void);
void	draw_player(void);
void	draw_square(t_pos pos, int size, int color);
void	draw_fov(void);
void	draw_minimap(void);
void	render_texture(t_ray *ray, int x);
void	raycast(void);
void	render_pixel(t_pos pos, int color);
void	free_matrix(char **matrix);
void	show_fps(long int old_time);
void	check_map(char **map);
int		handle_input(int key);
int		input_release(int key);
char	*ft_dtoa(double n, int decimal_n);
int		is_space(char c);
bool	is_floor(char c);
bool	is_wall(char c);
int		parse_data(char *argv);
char	**get_map(char *file);
int		valid_map(char *file);
int		invalid_characters(char *line);
int		top_bottom_walls(char *line, int line_nb);
int		invalid_walls(char **layout);
int		invalid_borders(char *line);
int		player_check(char **map);
int		map_conditions(char **layout);
int		check_move(t_pos move);
int		render_game(void);
int		rotate_camera(t_rotation rotation);
int		shader_floor(int dist, int color);
int		shader_ceiling(int dist, int color);
void	parse_map_textures(char *line);
int		shader(double wall_dist, int color);
int		file_check(char *file);
void	error_exit(char *error, char *file);
int		check_xpm(void);
int		check_order(void);
int		check_colors(void);
int		get_trgb(int t, int r, int g, int b);
long	get_time(void);
int		move_player(void);
int		quit_window(void);
int		mouse_handler(int x, int y);
void	print_map(char **map);
bool	only_walls(char *line);
bool	isdigitarray(char *str);

#endif