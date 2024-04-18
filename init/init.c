/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofadhel <ofadhel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 21:47:32 by ofadhel           #+#    #+#             */
/*   Updated: 2024/04/14 13:22:48 by ofadhel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

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

void	init_camera_frame(t_game *game)
{
	game->frame.time = 0;
	game->frame.old_time = 0;
	game->frame.frame_per_second = 0;
	game->frame.frame_time = 0;
	game->frame.fps = 0;
	game->camera.current_x = 0;
	game->camera.plane_x = 0;
	game->camera.plane_y = 0;
	game->camera.cam_move = 0;
}

void	init(t_game *game)
{
	init_parser(game);
	init_map(game);
	init_ray_and_player(game);
	init_textures(game);
	init_camera_frame(game);
	game->win_width = 1280;
	game->win_height = 720;
	game->mlx.init = 0;
	game->mlx.win = 0;
	game->mlx.img = 0;
	game->mlx.address = 0;
	game->mlx.bits_per_pixel = 0;
	game->mlx.size_line = 0;
	game->mlx.endian = 0;
	game->run = 0;
	game->wall.perp_wall_dist = 0;
	game->wall.hit = 0;
	game->wall.side = 0;
	game->draw.end_pos = 0;
	game->draw.start_pos = 0;
	game->draw.line_height = 0;
}
