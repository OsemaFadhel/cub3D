/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofadhel <ofadhel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 22:04:16 by ofadhel           #+#    #+#             */
/*   Updated: 2024/04/06 14:32:38 by ofadhel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	ray_pos_and_dir(t_game *game, int *x)
{
	game->camera.current_x = 2 * (*x) / (double)game->win_width - 1;
	game->ray.ray_dir_x = game->player.director_vector_x
		+ game->camera.plane_x * game->camera.current_x;
	game->ray.ray_dir_y = game->player.director_vector_y
		+ game->camera.plane_y * game->camera.current_x;
	game->player.map_x = (int) game->map.player_x;
	game->player.map_y = (int) game->map.player_y;
	if (game->ray.ray_dir_x == 0)
		game->ray.delta_dist_x = 1e30;
	else
		game->ray.delta_dist_x = fabs(1 / game->ray.ray_dir_x);
	if (game->ray.ray_dir_y == 0)
		game->ray.delta_dist_y = 1e30;
	else
		game->ray.delta_dist_y = fabs(1 / game->ray.ray_dir_y);
}

void	dda_algo(t_game *game)
{
	game->wall.hit = 0;
	while (game->wall.hit == 0)
	{
		if (game->ray.side_dist_x < game->ray.side_dist_y)
		{
			game->ray.side_dist_x += game->ray.delta_dist_x;
			game->player.map_x += game->ray.step_x;
			game->wall.side = 0;
		}
		else
		{
			game->ray.side_dist_y += game->ray.delta_dist_y;
			game->player.map_y += game->ray.step_y;
			game->wall.side = 1;
		}
		if (game->map.map[game->player.map_x][game->player.map_y] == '1')
			game->wall.hit = 1;
	}
}

void	step_and_side_distance(t_game *game)
{
	if (game->ray.ray_dir_x < 0)
	{
		game->ray.step_x = -1;
		game->ray.side_dist_x = ((int) game->map.player_x
				- game->player.map_x) * game->ray.delta_dist_x;
	}
	else
	{
		game->ray.step_x = 1;
		game->ray.side_dist_x = (game->player.map_x + 1.0
				- (int) game->map.player_x) * game->ray.delta_dist_x;
	}
	if (game->ray.ray_dir_y < 0)
	{
		game->ray.step_y = -1;
		game->ray.side_dist_y = ((int) game->map.player_y
				- game->player.map_y) * game->ray.delta_dist_y;
	}
	else
	{
		game->ray.step_y = 1;
		game->ray.side_dist_y = (game->player.map_y + 1.0
				- (int) game->map.player_y) * game->ray.delta_dist_y;
	}
	dda_algo(game);
}