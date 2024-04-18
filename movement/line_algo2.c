/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_algo2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofadhel <ofadhel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 21:57:47 by ofadhel           #+#    #+#             */
/*   Updated: 2024/04/14 13:25:05 by ofadhel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	cam_left(t_game *game)
{
	double	old_dir_x;
	double	plane_x;

	old_dir_x = game->player.director_vector_x;
	plane_x = game->camera.plane_x;
	game->player.director_vector_x = game->player.director_vector_x
		* cos(game->player.rot_speed) - game->player.director_vector_y
		* sin(game->player.rot_speed);
	game->player.director_vector_y = old_dir_x * sin(game->player.rot_speed)
		+ game->player.director_vector_y * cos(game->player.rot_speed);
	game->camera.plane_x = game->camera.plane_x
		* cos(game->player.rot_speed) - game->camera.plane_y
		* sin(game->player.rot_speed);
	game->camera.plane_y = plane_x * sin (game->player.rot_speed)
		+ game->camera.plane_y * cos(game->player.rot_speed);
}

void	cam_right(t_game *game)
{
	double	old_dir_x;
	double	plane_x;

	old_dir_x = game->player.director_vector_x;
	plane_x = game->camera.plane_x;
	game->player.director_vector_x = game->player.director_vector_x
		* cos(-game->player.rot_speed) - game->player.director_vector_y
		* sin(-game->player.rot_speed);
	game->player.director_vector_y = old_dir_x * sin(-game->player.rot_speed)
		+ game->player.director_vector_y * cos(-game->player.rot_speed);
	game->camera.plane_x = game->camera.plane_x * cos(-game->player.rot_speed)
		- game->camera.plane_y * sin(-game->player.rot_speed);
	game->camera.plane_y = plane_x * sin (-game->player.rot_speed)
		+ game->camera.plane_y * cos(-game->player.rot_speed);
}
