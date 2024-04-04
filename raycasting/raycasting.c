/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofadhel <ofadhel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 22:38:37 by ofadhel           #+#    #+#             */
/*   Updated: 2024/04/04 15:08:19 by ofadhel          ###   ########.fr       */
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
	draw->line_height = abs((int)(768 / wall->perp_wall_dist));
	draw->start_pos = -draw->line_height / 2 + (double)768 / 2;
	if (draw->start_pos < 0)
		draw->start_pos = 0;
	draw->end_pos = draw->line_height / 2 + (double)768 / 2;
	if (draw->end_pos >= 768)
		draw->end_pos = 768 - 1;
}
/*
void	draw_background(t_game *game)
{
	int	j;
	int	k;

	j = 0;
	k = 0;
	while (k < 1366) //change 1920 with size of the window
	{
		mlx_pixel_put(game->mlx.init, game->mlx.win, k, j, game->textures.ceil);
		while (j < 385)
		{
			mlx_pixel_put(game->mlx.init, game->mlx.win, k, j, game->textures.ceil);
			j++;
		}
		j = 0;
		k++;
	}
	j = 385;
	k = 0;
	while (k < 1366)
	{
		mlx_pixel_put(game->mlx.init, game->mlx.win, k, j, game->textures.floor);
		while (j < 768)
		{
			mlx_pixel_put(game->mlx.init, game->mlx.win, k, j, game->textures.floor);
			j++;
		}
		j = 385;
		k++;
	}
	//now raycasting for the walls
}*/

void	raycasting(t_game *game)
{
	int			x;

	x = 0;
	ft_ismoving(game);
	//draw_background(game);
	while (x < 1366)
	{
		ray_pos_and_dir(game, &x);
		ray_length(&game->ray);
		step_and_side_distance(&game->player, &game->ray, &game->map);
		dda_algo(&game->ray, &game->player,
			&game->wall, &game->map);
		perpendicular_ray_distance(&game->wall, &game->ray);
		calculate_height_line(&game->wall, &game->draw);
		draw_columns(game, &x);
		x++;
	}
}
