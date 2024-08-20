/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3D.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfiliagg <dfiliagg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 09:17:05 by dfiliagg          #+#    #+#             */
/*   Updated: 2023/09/08 10:33:38 by dfiliagg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_H
# define CUBE3D_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <math.h>
# include <fcntl.h>
# include "minilibx-linux/mlx.h"
# include "libft/libft.h"
# include "get_next_line/get_next_line.h"

# define RGB_RED 0x00FF0000
# define RGB_GREEN 0x0000FF00
# define RGB_BLUE 0x000000FF
# define RGB_YELLOW 0x00FFFF00
# define RGB_WHITE 0x00FFFFFF
# define RGB_DARK_GREY 0x00282828

# define NAME "cub3D"
# define WITH_TEXTURE 1
# define PLAYER_CHARACTERS "NSWE"
# define WIDTH 1280
# define HEIGHT 720
# define SPEED 3.0
# define ROT_SPEED 2.5
# define TEXTURE_SIZE 64
# define TILE_SET 10

typedef struct s_read_map {
	int		fd;
	int		i;
	int		j;
	char	*line;
	char	**map;
}				t_read_map;

typedef struct s_check_map {
	int		y;
	size_t	x;
	char	*str;
	int		pos_counter;
}				t_check_map;

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_point
{
	double	x;
	double	y;
}	t_point;

typedef struct s_map
{
	t_point		player_pos;
	char		**map;
	int			width;
	int			height;
}	t_map;

typedef struct s_textures
{
	char	*nord;
	char	*sud;
	char	*ovest;
	char	*est;
	int		floor[3];
	int		ceilling[3];
}	t_textures;

typedef struct s_raycast
{
	t_point		draw_start;
	t_point		draw_end;
	t_point		side_dist;
	t_point		delta_dist;
	t_point		ray_dir;
	double		perp_wall_dist;
	double		camera_x;
	int			side;
	int			hit;
	int			line_height;
	int			step_x;
	int			step_y;
	int			map_x;
	int			map_y;
	int			color;
}	t_raycast;

typedef struct s_minimap
{
	t_data		map;
	int			x;
	int			y;
	int			width;
	int			height;
	t_point		begin_ray;
	t_point		end_ray;
}	t_minimap;

typedef struct s_player
{
	t_point		pos;
	t_point		dir;
	t_point		mov_dir;
	t_point		plane;
	t_point		mov_speed;
	double		rot_speed;
	double		rot_dir;
}	t_player;

typedef struct s_game
{
	void		*mlx;
	void		*mlx_win;
	int			width;
	int			height;
	double		frame_time;
	int			wall_widths[13];
	int			wall_heights[13];
	t_textures	tex;
	t_map		map;
	t_minimap	minimap;
	t_player	player;
	t_raycast	ray;
	t_data		data;
	t_data		walls[13];
	t_data		screen;
}	t_game;

int		map_converter(t_game *game, char *path, int fd);
int		border_check(t_game *game);
int		arg_check(int argc, char **argv);
int		parse_map(t_game *game, char *path);
int		free_game(t_game *game);

/*Movement*/
void	update_inputs(t_game *game);
int		input_on_press(int key, t_game *game);
int		input_on_release(int key, t_game *game);

/*drawing*/
void	raycaster_flat(t_game *game);
int		draw_frame(t_game *game);
void	draw_line_on(t_data *img, t_point begin, t_point end, int color);
void	draw_line(t_game *game, t_point begin, t_point end, int color);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	draw_texture(t_game *game, int x);
int		create_trgb(int t, int r, int g, int b);
void	draw_square(t_data *img, t_point start, int side, int color);
void	draw_minimap(t_game *game);

/*Init*/
void	init(t_game *game);
int		set_player(t_game *game);

/*Map Parser*/
void	free_string(char *str);
void	free_mat(char **mat);
int		read_m(t_game *game, char *file);
int		read_map(t_game *game, char*line, int fd);
int		parsing(int argc, char **argv, t_game *game);
int		count_char(char *str, char c);
int		check_color(int n);
int		s_tex(t_game *game, char *line, char *c);
int		free_texture(t_game *game);
int		check_one(char *str);
int		bad_chr(char *str);
int		check_letters(char **map);
int		check_min_max(t_game *game, char c, char **mat);
void	print_map(char **mat);
int		check_first_wall(t_game *game);
int		ft_check_map2(char **map);
void	get_map_hw(t_game *game);
void	error(t_game *game, char *msg);
void	fill_one(t_game *game);
void	check_last_z(t_game *game);
void	fill_space(t_game *game);
void	check_empty_file(char *s);
void	check_one_last(t_game *game);

#endif