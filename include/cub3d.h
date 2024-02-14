/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofadhel <ofadhel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 12:04:34 by ofadhel           #+#    #+#             */
/*   Updated: 2024/02/14 18:01:17 by ofadhel          ###   ########.fr       */
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
	char	**map;
	t_pars	pars;
	int	ceil_color;
	int	floor_color;
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


#endif
