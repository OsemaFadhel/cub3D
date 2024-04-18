/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofadhel <ofadhel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 13:22:29 by ofadhel           #+#    #+#             */
/*   Updated: 2024/04/14 13:22:50 by ofadhel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	init_map(t_game *game)
{
	game->map.map = 0;
	game->map.player_orientation = 0;
	game->map.start_line = 0;
	game->map.width = 0;
	game->map.height = 0;
	game->map.x = 0;
	game->map.y = 0;
	game->map.player_found = 0;
	game->map.player_x = 0;
	game->map.player_y = 0;
	game->map.player_patch = 0;
	game->map.map_error = 0;
	game->map.floor = 0;
	game->map.ceiling = 0;
}

void	init_ray_and_player(t_game *game)
{
	game->ray.ray_dir_x = 0;
	game->ray.ray_dir_y = 0.66;
	game->ray.side_dist_x = 0;
	game->ray.side_dist_y = 0;
	game->ray.delta_dist_x = 0;
	game->ray.delta_dist_y = 0;
	game->ray.step_x = 0;
	game->ray.step_y = 0;
	game->player.map_x = 0;
	game->player.map_y = 0;
	game->player.director_vector_x = 0;
	game->player.director_vector_y = 0;
	game->player.move_flag_x = 0;
	game->player.move_flag_y = 0;
	game->player.move_speed = 0;
	game->player.rot_speed = 0;
}

void	init_textures(t_game *game)
{
	game->textures.wall_x = 0;
	game->textures.x = 0;
	game->textures.y = 0;
	game->textures.stored[0] = 0;
	game->textures.stored[1] = 0;
	game->textures.stored[2] = 0;
	game->textures.stored[3] = 0;
	game->textures.height = 64;
	game->textures.width = 64;
	game->textures.choice = 0;
	game->textures.colour = 0;
	game->textures.ceil = 0;
	game->textures.floor = 0;
	game->textures.wall_no = 0;
	game->textures.wall_so = 0;
	game->textures.wall_ea = 0;
	game->textures.wall_we = 0;
}
