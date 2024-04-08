/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_algo2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofadhel <ofadhel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 21:57:47 by ofadhel           #+#    #+#             */
/*   Updated: 2024/04/08 14:19:51 by ofadhel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	cam_left(t_game *game)
{
	double	dir_x;
	double	plane_x;
	double	speed;

	speed = 0.08;
	dir_x = game->player.director_vector_x;
	plane_x = game->camera.plane_x;
	game->player.director_vector_x = game->player.director_vector_x
		* cos(speed) - game->player.director_vector_y * sin(speed);
	game->player.director_vector_y = dir_x * sin(speed)
		+ game->player.director_vector_y * cos(speed);
	game->camera.plane_x = game->camera.plane_x
		* cos(speed) - game->camera.plane_y * sin(speed);
	game->camera.plane_y = plane_x * sin (speed)
		+ game->camera.plane_y * cos(speed);
}

void	cam_right(t_game *game)
{
	double	dir_x;
	double	plane_x;
	double	speed;

	speed = 0.08;
	dir_x = game->player.director_vector_x;
	plane_x = game->camera.plane_x;
	game->player.director_vector_x = game->player.director_vector_x
		* cos(-speed) - game->player.director_vector_y * sin(-speed);
	game->player.director_vector_y = dir_x * sin(-speed)
		+ game->player.director_vector_y * cos(-speed);
	game->camera.plane_x = game->camera.plane_x * cos(-speed)
		- game->camera.plane_y * sin(-speed);
	game->camera.plane_y = plane_x * sin (-speed)
		+ game->camera.plane_y * cos(-speed);
}
