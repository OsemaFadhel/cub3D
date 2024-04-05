/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofadhel <ofadhel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 22:04:16 by ofadhel           #+#    #+#             */
/*   Updated: 2024/04/05 16:45:18 by ofadhel          ###   ########.fr       */
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
}

void	ray_length(t_ray *ray)
{
	if (ray->ray_dir_x == 0)
		ray->delta_dist_x = 1e30;
	else
		ray->delta_dist_x = fabs(1 / ray->ray_dir_x);
	if (ray->ray_dir_y == 0)
		ray->delta_dist_y = 1e30;
	else
		ray->delta_dist_y = fabs(1 / ray->ray_dir_y);
}

void	step_and_side_distance(t_player *player, t_ray *ray, t_map *map)
{
	if (ray->ray_dir_x < 0)
	{
		ray->step_x = -1;
		ray->side_dist_x = ((int) map->player_x
				- player->map_x) * ray->delta_dist_x;
	}
	else
	{
		ray->step_x = 1;
		ray->side_dist_x = (player->map_x + 1.0
				- (int) map->player_x) * ray->delta_dist_x;
	}
	if (ray->ray_dir_y < 0)
	{
		ray->step_y = -1;
		ray->side_dist_y = ((int) map->player_y
				- player->map_y) * ray->delta_dist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_dist_y = (player->map_y + 1.0
				- (int) map->player_y) * ray->delta_dist_y;
	}
}

void	dda_algo(t_ray *ray, t_player *player,
	t_wall *wall, t_map *map)
{
	wall->hit = 0;
	while (wall->hit == 0)
	{
		if (ray->side_dist_x < ray->side_dist_y)
		{
			ray->side_dist_x += ray->delta_dist_x;
			player->map_x += ray->step_x;
			wall->side = 0;
		}
		else
		{
			ray->side_dist_y += ray->delta_dist_y;
			player->map_y += ray->step_y;
			wall->side = 1;
		}
		if (map->map[player->map_x][player->map_y] == '1')
			wall->hit = 1;
	}
}
