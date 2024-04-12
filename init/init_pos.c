/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_pos.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofadhel <ofadhel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 22:00:47 by ofadhel           #+#    #+#             */
/*   Updated: 2024/04/12 14:28:31 by ofadhel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static void	init_camera_position_ns(t_player *player, t_map *map,
	t_camera *camera)
{
	if (map->player_orientation == 'N')
	{
		player->director_vector_x = -1;
		player->director_vector_y = 0;
		camera->plane_x = 0;
		camera->plane_y = 0.66;
	}
	if (map->player_orientation == 'S')
	{
		player->director_vector_x = 1;
		player->director_vector_y = 0;
		camera->plane_x = 0;
		camera->plane_y = -0.66;
	}
}

static void	init_camera_position_ew(t_player *player, t_map *map,
	t_camera *camera)
{
	if (map->player_orientation == 'E')
	{
		player->director_vector_x = 0;
		player->director_vector_y = 1;
		camera->plane_x = 0.66;
		camera->plane_y = 0;
	}
	if (map->player_orientation == 'W')
	{
		player->director_vector_x = 0;
		player->director_vector_y = -1;
		camera->plane_x = -0.66;
		camera->plane_y = 0;
	}
}

void	init_camera_position(t_player *player, t_map *map, t_camera *camera)
{
	if (map->player_orientation == 'N' || map->player_orientation == 'S')
		init_camera_position_ns(player, map, camera);
	else if (map->player_orientation == 'E' || map->player_orientation == 'W')
		init_camera_position_ew(player, map, camera);
}
