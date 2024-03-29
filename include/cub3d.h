/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofadhel <ofadhel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 12:04:34 by ofadhel           #+#    #+#             */
/*   Updated: 2024/03/29 22:14:16 by ofadhel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>
# include <string.h>
# include <errno.h>
# include "../mlx_linux/mlx.h"
# include "../mlx_linux/mlx_int.h"
# include "../libft/libft.h"

# define LEFT 123
# define RIGHT 124
# define W 13
# define A 0
# define S 1
# define D 2
# define ESC 53
# define NORTH_SOUTH 1
# define EAST_WEST 0

typedef struct s_axis
{
	int	x;
	int	y;
}				t_axis;

typedef struct s_dbl
{
	double	x;
	double	y;
}				t_dbl;

typedef struct s_player
{
	int		move_flag_x;
	int		move_flag_y;
	double	director_vector_x;
	double	director_vector_y;
	int		map_x;
	int		map_y;
}	t_player;

typedef struct s_camera
{
	double	plane_x;
	double	plane_y;
	double	current_x;
}	t_camera;

typedef struct s_ray
{
	double	ray_dir_x;
	double	ray_dir_y;
	double	side_dist_x;
	double	side_dist_y;
	double	delta_dist_x;
	double	delta_dist_y;
	int		step_x;
	int		step_y;
}	t_ray;

typedef struct s_wall
{
	double	perp_wall_dist;
	int		hit;
	int		side;
}	t_wall;

typedef struct s_draw
{
	int	line_height;
	int	start_pos;
	int	end_pos;
}	t_draw;

typedef struct s_mlx
{
	void	*init;
	void	*win;
	void	*img;
	char	*address;
	int		endian;
	int		bits_per_pixel;
	int		size_line;
}	t_mlx;

typedef struct s_map
{
	char			**map;
	char			player_orientation;
	int				width;
	int				height;
	int				start_line;
	int				x;
	int				y;
	int				player_found;
	double			player_x;
	double			player_y;
	int				map_error;
	int				player_patch;
	unsigned int	floor;
	unsigned int	ceiling;
}	t_map;

typedef struct s_textures
{
	double	wall_x;
	int		x;
	int		y;
	char	*stored[4];
	int		width;
	int		height;
	int		choice;
	int		colour;
	int		ceil;
	int		floor;
	void	*wall_no;
	void	*wall_so;
	void	*wall_we;
	void	*wall_ea;
}	t_textures;

typedef struct s_pars
{
	char	**file;
	t_dbl	plane;
	t_dbl	dir;
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	char	*f;
	char	*c;
	int		ceil[3];
	int		floor[3];
	int		l;
	int		m;
	int		k;
}				t_pars;

typedef struct s_game
{
	int			run;
	t_map		map;
	t_pars		pars;
	t_wall		wall;
	t_player	player;
	t_camera	camera;
	t_draw		draw;
	t_ray		ray;
	t_textures	textures;
	t_mlx		mlx;
	t_axis		*map_axis;
	t_dbl		player_dbl;
}				t_game;

/* init */

void	init(t_game *game);
void	init_camera_position(t_player *player, t_map *map, t_camera *camera);

/* utils */

int		print_matrix(char **matrix);
void	free_matrix(char **matrix);

/* parser.c */

void	read_file(char *file, t_game *game);
void	parser(char **av, t_game *game);
void	parse_map(t_game *game, int i);
void	check_file(t_game *game);
void	read_file(char *file, t_game *game);
void	check_textures(t_game *game);
void	check_closed(t_game *game);
void	check_map_name(char *str);
void	set_rgb(t_game *game);
int		get_map_size(t_game *game);
int		get_map_width(t_game *game, int i);
void	check_characters(t_game *game);
void	check_closed_top(t_game *game);
void	check_closed_bottom(t_game *game, int y);
void	check_closed_edges(t_game *game);
void	check_space_left_up(t_game *game, int y, int x);
void	check_space_left_down(t_game *game, int y, int x);

/* image_convert.c */

void	ft_mlx_xpm_file_to_image(t_mlx *mlx, t_game *game);

/* raycasting.c */

void	raycasting(t_game *game);
int		game_loop(t_game *game);
void	draw_columns(t_game *game, int *x);
void	dda_algo(t_ray *ray, t_player *player, t_wall *wall, t_map *map);
void	step_and_side_distance(t_player *player, t_ray *ray, t_map *map);
void	ray_length(t_ray *ray);
void	ray_pos_and_dir(t_game *game, int *x);

/* movement */

int		ft_key_press(int keycode, t_game *game);
int		ft_key_release(int keycode, t_game *game);
void	ft_ismoving(t_game *game);

/* exit.c */

int		ft_exit(t_game *game, int i);
int		ft_key_press(int keycode, t_game *game);
void	ft_front(t_game *game);
void	ft_back(t_game *game);
void	ft_left(t_game *game);
void	ft_right(t_game *game);
void	cam_left(t_game *game);
void	cam_right(t_game *game);

#endif
