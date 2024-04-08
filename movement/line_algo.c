/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofadhel <ofadhel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 12:34:48 by ofadhel           #+#    #+#             */
/*   Updated: 2024/03/29 21:58:16 by ofadhel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	ft_front(t_game *game, double c)
{
	int	x;
	int	y;
	//double	c = 0.1;

	if (game->run == 1)
	{
		c = 0.1;
	}

	x = game->map.player_x + (game->player.director_vector_x + 0.01) * c;
	y = game->map.player_y + (game->player.director_vector_y + 0.01) * c;
	if (game->map.map[x][(int)game->map.player_y] != '1')
	{
		game->map.player_x += game->player.director_vector_x * c;
	}
	if (game->map.map[(int)(game->map.player_x)][y] != '1')
	{
		game->map.player_y += game->player.director_vector_y * c;
	}
}

void	ft_back(t_game *game)
{
	int		x;
	int		y;

	double c = 0.01;
	x = game->map.player_x - (game->player.director_vector_x + 0.01) * c;
	y = game->map.player_y - (game->player.director_vector_y + 0.01) * c;
	if (game->map.map[x][(int)game->map.player_y] != '1')
	{
		game->map.player_x -= game->player.director_vector_x * c;
	}
	if (game->map.map[(int)(game->map.player_x)][y] != '1')
	{
		game->map.player_y -= game->player.director_vector_y * c;
	}
}

void	ft_left(t_game *game)
{
	int	x;
	int	y;

	double c = 0.01;
	x = game->map.player_x - (game->camera.plane_x + 0.01) * c;
	y = game->map.player_y - (game->camera.plane_y + 0.01) * c;
	if (game->map.map[x][(int)game->map.player_y] != '1')
	{
		game->map.player_x -= game->camera.plane_x * c;
	}
	if (game->map.map[(int)game->map.player_x][y] != '1')
	{
		game->map.player_y -= game->camera.plane_y * c;
	}
}

void	ft_right(t_game *game)
{
	int	x;
	int	y;

	double c = 0.01;
	x = game->map.player_x + (game->camera.plane_x + 0.01) * c;
	y = game->map.player_y + (game->camera.plane_y + 0.01) * c;
	if (game->map.map[x][(int)game->map.player_y] != '1')
	{
		game->map.player_x += game->camera.plane_x * c;
	}
	if (game->map.map[(int)game->map.player_x][y] != '1')
	{
		game->map.player_y += game->camera.plane_y * c;
	}
}

void	ft_ismoving(t_game *game)
{
	double c = 0.1;
	if (game->player.move_flag_y == 1)
		ft_front(game, c);
	if (game->player.move_flag_y == -1)
		ft_back(game);
	if (game->player.move_flag_x == -1)
		ft_left(game);
	if (game->player.move_flag_x == 1)
		ft_right(game);
}
