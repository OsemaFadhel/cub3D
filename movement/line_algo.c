/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofadhel <ofadhel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 12:34:48 by ofadhel           #+#    #+#             */
/*   Updated: 2024/04/10 20:5:18 by ofadhel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	ft_front(t_game *game) //, double c)
{
	int	x;
	int	y;
	double	c = 2;

	/*if (game->run == 1)
	{
		c = 0.1;
	}*/

	x = game->map.player_x + (game->player.director_vector_x) * c;
	y = game->map.player_y + (game->player.director_vector_y) * c;
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
	double c = 2;
	x = game->map.player_x - (game->player.director_vector_x) * c;
	y = game->map.player_y - (game->player.director_vector_y) * c;
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

	double c = 2;
	x = game->map.player_x - (game->camera.plane_x) * c;
	y = game->map.player_y - (game->camera.plane_y) * c;
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

	double c = 2;
	x = game->map.player_x + (game->camera.plane_x) * c;
	y = game->map.player_y + (game->camera.plane_y) * c;
	if (game->map.map[x][(int)game->map.player_y] != '1')
	{
		game->map.player_x += game->camera.plane_x * c;
	}
	if (game->map.map[(int)game->map.player_x][y] != '1')
	{
		game->map.player_y += game->camera.plane_y * c;
	}
}
