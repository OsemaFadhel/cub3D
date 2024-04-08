/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofadhel <ofadhel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 21:47:32 by ofadhel           #+#    #+#             */
/*   Updated: 2024/04/08 14:20:44 by ofadhel          ###   ########.fr       */
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

void	init_parser(t_game *game)
{
	game->pars.file = NULL;
	game->pars.no = NULL;
	game->pars.so = NULL;
	game->pars.we = NULL;
	game->pars.ea = NULL;
	game->pars.f = NULL;
	game->pars.c = NULL;
	game->pars.ceil[0] = -1;
	game->pars.ceil[1] = -1;
	game->pars.ceil[2] = -1;
	game->pars.floor[0] = -1;
	game->pars.floor[1] = -1;
	game->pars.floor[2] = -1;
	game->pars.l = 0;
	game->pars.m = 0;
	game->pars.k = 0;
}

void	init(t_game *game)
{
	init_parser(game);
	init_map(game);
	init_ray_and_player(game);
	init_textures(game);
	game->win_width = 1366;
	game->win_height = 768;
	game->mlx.init = 0;
	game->mlx.win = 0;
	game->mlx.img = 0;
	game->mlx.address = 0;
	game->mlx.bits_per_pixel = 0;
	game->mlx.size_line = 0;
	game->mlx.endian = 0;
	game->run = 0;
	game->time = 0;
	game->old_time = 0;
	game->frame_per_second = 0;
	game->frame_time = 0;
	game->camera.current_x = 0;
	game->camera.plane_x = 0;
	game->camera.plane_y = 0;
	game->wall.perp_wall_dist = 0;
	game->wall.hit = 0;
	game->wall.side = 0;
	game->draw.end_pos = 0;
	game->draw.start_pos = 0;
	game->draw.line_height = 0;
}
