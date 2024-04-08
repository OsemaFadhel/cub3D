/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofadhel <ofadhel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 22:38:37 by ofadhel           #+#    #+#             */
/*   Updated: 2024/04/06 14:32:28 by ofadhel          ###   ########.fr       */
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
	game->draw.line_height = abs((int)(game->win_height / game->wall.perp_wall_dist));
	game->draw.start_pos = -game->draw.line_height / 2 + game->win_height / 2;
	if (game->draw.start_pos < 0)
		game->draw.start_pos = 0;
	game->draw.end_pos = game->draw.line_height / 2 + game->win_height / 2;
	if (game->draw.end_pos >= game->win_height)
		game->draw.end_pos = game->win_height - 1;
}

void	raycasting(t_game *game)
{
	int			x;

	x = 0;
	while (x < game->win_width)
	{
		ray_pos_and_dir(game, &x);
		step_and_side_distance(game);
		perpendicular_ray_distance(game);
		draw_columns(game, &x);
		//get_frame_time(game);
		ft_ismoving(game);
		x++;
	}
}