/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofadhel <ofadhel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 21:47:32 by ofadhel           #+#    #+#             */
/*   Updated: 2024/03/03 23:48:51 by ofadhel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	init_map(t_game *game)
{
	game->map.map = 0;
	game->map.player_orientation = 0;
	game->map.start_line = 0;
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
	game->ray.direction_x = 0;
	game->ray.direction_y = 0;
	game->ray.move_to_next_x = 0;
	game->ray.move_to_next_y = 0;
	game->ray.distance_to_next_x = 0;
	game->ray.distance_to_next_y = 0;
	game->ray.step_in_x = 0;
	game->ray.step_in_y = 0;
	game->player.current_square_x = 0;
	game->player.current_square_y = 0;
	game->player.director_vector_x = 0;
	game->player.director_vector_y = 0;
}

void	init_textures(t_game *game)
{
	game->textures.wall_x = 0;
	game->textures.x = 0;
	game->textures.y = 0;
	game->textures.stored[0] = NULL;
	game->textures.stored[1] = NULL;
	game->textures.stored[2] = NULL;
	game->textures.stored[3] = NULL;
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

void init_parser(t_game *game)
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
}

void	init(t_game *game)
{
	init_map(game);
	init_ray_and_player(game);
	init_textures(game);
	game->win_width = 1366;
	game->win_height = 769;
	game->size_line = 0;
	game->bpp = 0;
	game->endian = 0;
	game->data_addr = NULL;
	game->camera.current_x = 0;
	game->camera.plane_x = 0;
	game->camera.plane_y = 0;
	game->wall.shortest_dist_to_wall = 0;
	game->wall.is_hit = 0;
	game->wall.which_side_hit = 0;
	game->draw.end_pos = 0;
	game->draw.start_pos = 0;
	game->draw.line_height = 0;
}
