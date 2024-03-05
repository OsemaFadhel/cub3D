/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofadhel <ofadhel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 12:34:48 by ofadhel           #+#    #+#             */
/*   Updated: 2024/02/12 17:56:05 by ofadhel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	ft_front(t_game *game)
{
	int	x;
	int	y;

	x = game->map.player_x + (game->player.director_vector_x + 0.01)
		* 0.1;
	y = game->map.player_y + (game->player.director_vector_y + 0.01)
		* 0.1;
	if (game->map.map[x][(int)game->map.player_y] != '1')
	{
		game->map.player_x += game->player.director_vector_x * 0.1;
	}
	if (game->map.map[(int)(game->map.player_x)][y] != '1')
	{
		game->map.player_y += game->player.director_vector_y * 0.1;
	}
}

void	ft_back(t_game *game)
{
	int	x;
	int	y;

	x = game->map.player_x - (game->player.director_vector_x + 0.01) * 0.1;
	y = game->map.player_y - (game->player.director_vector_y + 0.01) * 0.1;
	if (game->map.map[x][(int)game->map.player_y] != '1')
	{
		game->map.player_x -= game->player.director_vector_x * 0.1;
	}
	if (game->map.map[(int)(game->map.player_x)][y] != '1')
	{
		game->map.player_y -= game->player.director_vector_y * 0.1;
	}
}

void	ft_left(t_game *game)
{
	int	x;
	int	y;

	x = game->map.player_x - (game->camera.plane_x + 0.01) * 0.1;
	y = game->map.player_y - (game->camera.plane_y + 0.01) * 0.1;
	if (game->map.map[x][(int)game->map.player_y] != '1')
	{
		game->map.player_x -= game->camera.plane_x * 0.1;
	}
	if (game->map.map[(int)game->map.player_x][y] != '1')
	{
		game->map.player_y -= game->camera.plane_y * 0.1;
	}
}

void	ft_right(t_game *game)
{
	int	x;
	int	y;

	x = game->map.player_x + (game->camera.plane_x + 0.01) * 0.1;
	y = game->map.player_y + (game->camera.plane_y + 0.01) * 0.1;
	if (game->map.map[x][(int)game->map.player_y] != '1')
	{
		game->map.player_x += game->camera.plane_x * 0.1;
	}
	if (game->map.map[(int)game->map.player_x][y] != '1')
	{
		game->map.player_y += game->camera.plane_y * 0.1;
	}
}

void	cam_left(t_game *game)
{
	double	old_director_vector_x;
	double	old_camera_plane_x;

	old_director_vector_x = game->player.director_vector_x;
	old_camera_plane_x = game->camera.plane_x;
	game->player.director_vector_x = game->player.director_vector_x
		* cos(0.1) - game->player.director_vector_y * sin(0.1);
	game->player.director_vector_y = old_director_vector_x * sin(0.1)
		+ game->player.director_vector_y * cos(0.1);
	game->camera.plane_x = game->camera.plane_x * cos(0.1)
		- game->camera.plane_y * sin(0.1);
	game->camera.plane_y = old_camera_plane_x * sin (0.1)
		+ game->camera.plane_y * cos(0.1);
}

void	cam_right(t_game *game)
{
	double	old_director_vector_x;
	double	old_camera_plane_x;

	old_director_vector_x = game->player.director_vector_x;
	old_camera_plane_x = game->camera.plane_x;
	game->player.director_vector_x = game->player.director_vector_x
		* cos(-0.1) - game->player.director_vector_y * sin(-0.1);
	game->player.director_vector_y = old_director_vector_x
		* sin(-0.1) + game->player.director_vector_y * cos(-0.1);
	game->camera.plane_x = game->camera.plane_x * cos(-0.1)
		- game->camera.plane_y * sin(-0.1);
	game->camera.plane_y = old_camera_plane_x * sin (-0.1)
		+ game->camera.plane_y * cos(-0.1);
}

/*function line(int x0, int x1, int y0, int y1)
{
	int deltax := abs(x1 - x0)
	int deltay := abs(y1 - y0)
	int error := 0
	int deltaerr := (deltay + 1)
	int y := y0
	int diry := y1 - y0
	if diry > 0
		diry = 1
	if diry < 0
		diry = -1
	for x from x0 to x1
	{
		plot(x,y)
		error := error + deltaerr
		if error >= (deltax + 1)
		{
			y := y + diry
			error := error - (deltax + 1)
		}
	}
}*/
