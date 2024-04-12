/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofadhel <ofadhel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 22:38:37 by ofadhel           #+#    #+#             */
/*   Updated: 2024/04/12 16:03:49 by ofadhel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	perpendicular_ray_distance(t_game *game)
{
	if (game->wall.side == 0)
		game->wall.perp_wall_dist = (game->ray.side_dist_x
				- game->ray.delta_dist_x);
	else
		game->wall.perp_wall_dist = (game->ray.side_dist_y
				- game->ray.delta_dist_y);
	game->draw.line_height = (int)(game->win_height
				/ game->wall.perp_wall_dist);
	game->draw.start_pos = -game->draw.line_height / 2 + game->win_height / 2;
	if (game->draw.start_pos < 0)
		game->draw.start_pos = 0;
	game->draw.end_pos = game->draw.line_height / 2 + game->win_height / 2;
	if (game->draw.end_pos >= game->win_height)
		game->draw.end_pos = game->win_height - 1;
}

void	ft_ismoving(t_game *game)
{
	if (game->player.move_flag_y == 1)
		ft_front(game);
	if (game->player.move_flag_y == -1)
		ft_back(game);
	if (game->player.move_flag_x == 1)
		ft_right(game);
	if (game->player.move_flag_x == -1)
		ft_left(game);
	if (game->camera.cam_move == 1)
		cam_right(game);
	if (game->camera.cam_move == -1)
		cam_left(game);
}

void	raycasting(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	//printf("player pos x= %d, y= %d\n", (int)game->map.player_y, (int)game->map.player_x);
	while (x < game->win_width)
	{
		y = 0;
		ray_pos_and_dir(game, &x);
		step_and_side_distance(game);
		perpendicular_ray_distance(game);
		draw_columns(game, &x);
		y += fill_wall_texture(game, &x, y);
		fill_floor_and_ceiling(game, &x, y);
		x++;
	}
	ft_ismoving(game);
}
