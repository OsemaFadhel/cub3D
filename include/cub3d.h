/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofadhel <ofadhel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 12:04:34 by ofadhel           #+#    #+#             */
/*   Updated: 2024/03/03 23:59:42 by ofadhel          ###   ########.fr       */
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

# define LEFT 123
# define RIGHT 124
# define W 13
# define A 0
# define S 1
# define D 2


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
	t_dbl   plane;
	t_dbl   dir;
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	char	*f;
	char	*c;
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
	int		size_line;
	int 	bpp;
	int		endian;
	char	*data_addr;
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
void	read_file(char *file, t_game *game);
void	check_textures(t_game *game);
void	check_closed(t_game *game);
void	check_map_name(char *str);
void	set_rgb(t_game *game);

/* image_convert.c */

void	to_xpm(t_mlx *mlx, t_game *game);

/* raycasting.c */

int		game_loop(t_game *game);
void	draw_columns(t_game *game, int *x);

/* movement */

int		ft_key_press(int keycode, t_game *game);
int		ft_key_release(int	keycode, t_game *game);


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
