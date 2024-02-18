/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofadhel <ofadhel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 12:04:34 by ofadhel           #+#    #+#             */
/*   Updated: 2024/02/18 02:56:42 by ofadhel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <stdlib.h>
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

typedef struct s_ray
{
	double	distance;
	double	line_len;
	t_dbl	dir;
	t_dbl	step_size;
	t_dbl	touch_point;
 	t_dbl	start;
	t_dbl	len;
	t_axis	map_check;
	t_axis	step;
	//t_bool	hit;  //se trova un muro
	int hit;
	int vertical;
	//t_bool	vertical;
}				t_ray;

typedef struct s_pars
{
	char	**file;
	char	*no;
	char	*so;
	char	*ea;
	char	*we;
	char	*f;
	char	*c;
	int		ceil[3];
	int		floor[3];
}				t_pars;

typedef struct s_game
{
	void	*mlx;
	void	*win;
	void	*img;
	char	**map;
	char	**map_array;
	t_pars	pars;
	t_axis	*map_axis;
	t_dbl	player_axis;
	int		win_width;
	int		win_height;
	int		ceil_color;
	int		floor_color;
	int		size_line;
	int 	bpp;
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

void	read_file(char *file, t_game *game);
void	parser(char **av, t_game *game);
void	read_file(char *file, t_game *game);
void	check_textures(t_game *game);
void	check_closed(t_game *game, int i);
void	check_map_name(char *str);
void	set_rgb(t_game *game);

/* raycasting */

void	initialize_ray(t_game *game, t_ray *ray, double angle);
double	raylen(t_game *game, t_ray *ray, double angle);
void	ray_casting(t_game *game, t_ray *ray);
int		ft_max(int a, int b);
void	draw_background(t_game *game, int j, int k);

#endif
