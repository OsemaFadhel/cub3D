/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofadhel <ofadhel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 22:38:37 by ofadhel           #+#    #+#             */
/*   Updated: 2024/03/29 22:07:21 by ofadhel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	perpendicular_ray_distance(t_wall *wall, t_ray *ray)
{
	if (wall->side == 0)
		wall->perp_wall_dist = (ray->side_dist_x
				- ray->delta_dist_x);
	else
		wall->perp_wall_dist = (ray->side_dist_y
				- ray->delta_dist_y);
}

void	calculate_height_line(t_wall *wall, t_draw *draw)
{
	draw->line_height = abs((int)(769 / wall->perp_wall_dist));
	draw->start_pos = -draw->line_height / 2 + (double)769 / 2;
	if (draw->start_pos < 0)
		draw->start_pos = 0;
	draw->end_pos = draw->line_height / 2 + (double)769 / 2;
	if (draw->end_pos >= 769)
		draw->end_pos = 769 - 1;
}

void	raycasting(t_game *game)
{
	int			x;

	x = 0;
	ft_ismoving(game);
	while (x <= 1366)
	{
		ray_pos_and_dir(game, &x);
		ray_length(&game->ray);
		step_and_side_distance(&game->player, &game->ray, &game->map);
		dda_algo(&game->ray, &game->player,
			&game->wall, &game->map);
		perpendicular_ray_distance(&game->wall, &game->ray);
		calculate_height_line(&game->wall, &game->draw);
		draw_columns(game, &x);
		++x;
	}
}
