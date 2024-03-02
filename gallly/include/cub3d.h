/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofadhel <ofadhel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 12:04:34 by ofadhel           #+#    #+#             */
/*   Updated: 2024/02/27 23:17:56 by ofadhel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef cub3d_H
# define cub3d_H

# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>
# include <string.h>
# include <errno.h>
# include <mlx.h>
# include "../libft/libft.h"

# define UP 126
# define DOWN 125
# define LEFT 123
# define RIGHT 124

# define ESC 53

#  define NORTH_SOUTH 1
#  define EAST_WEST 0

typedef struct s_axis
{
	int x;
	int y;
}				t_axis;

typedef struct s_dbl
{
	double x;
	double y;
}				t_dbl;

typedef struct s_player
{
	double	director_vector_x;
	double	director_vector_y;
	int		current_square_x;
	int		current_square_y;
}	t_player;

typedef struct s_camera
{
	double	plane_x;
	double	plane_y;
	double	current_x;
}	t_camera;

typedef struct s_ray
{
	double	direction_x;
	double	direction_y;
	double	move_to_next_x;
	double	move_to_next_y;
	double	distance_to_next_x;
	double	distance_to_next_y;
	int		step_in_x;
	int		step_in_y;
}	t_ray;

typedef struct s_wall
{
	double	shortest_dist_to_wall;
	int		is_hit;
	int		which_side_hit;
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
	int		line_length;
}	t_mlx;

typedef struct s_map
{
	char			**map;
	char			player_orientation;
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
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	char	*f;
	char	*c;
	void	*wall_no;
	void	*wall_so;
	void	*wall_we;
	void	*wall_ea;
}	t_textures;

typedef struct s_pars
{
	char	**file;
	char	*no;
	char	*so;
	char	*ea;
	char	*we;
	char	*f;
	char	*c;
	t_dbl   plane;
	t_dbl   dir;
	int		ceil[3];
	int		floor[3];
}				t_pars;

typedef struct s_game
{
	t_map map;
	t_pars	pars;
	t_wall		wall;
	t_player	player;
	t_camera	camera;
	t_draw		draw;
	t_ray	ray;
	t_textures textures;
	t_mlx	mlx;
	t_axis	*map_axis;
	t_dbl	player_dbl;
	int		win_width;
	int		win_height;
	int		ceil_color;
	int		floor_color;
	int		size_line;
	int 	bpp;
	int		endian;
	char	*data_addr;
	void	*floor_texture;
	void	*ceil_texture;
	void	*north_texture;
	void	*south_texture;
	void	*east_texture;
	void	*west_texture;
}				t_game;

int		key(int keycode, t_game *game);
void	init(t_game *game);
int		ft_exit(t_game *game, int i);
int		print_matrix(char **matrix);
void	free_matrix(char **matrix);

/* parser */

//void	init_struc(char **av, t_game *game);
void	init_struc(char *av);
void	read_file(char *file, t_game *game);
void	parser(char **av, t_game *game);
void	read_file(char *file, t_game *game);
void	check_textures(t_game *game);
void	check_closed(t_game *game, int i);
void	check_map_name(char *str);
void	set_rgb(t_game *game);

/* raycasting */

//void	initialize_ray(t_game *game, t_ray *ray, double angle);
void	initialize_ray(t_game *game, int x, t_ray *ray);
double	raylen(t_game *game, t_ray *ray, double angle);
void	ray_casting(t_game *game, t_ray *ray);
int		ft_max(int a, int b);
void	draw_background(t_game *game, int j, int k);
int		draw_map(void *param);
int		check_file2(char *file, t_game *cub);
void	error(t_game *game, char *str, int code);

#endif
