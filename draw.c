/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofadhel <ofadhel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 22:03:25 by ofadhel           #+#    #+#             */
/*   Updated: 2024/02/21 22:03:34 by ofadhel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/cub3d.h"

void	get_minlen(t_game *game)
{
	if (game->ray->touch_point == 0)
		game->ray->min_line_len = (game->ray->movement.x - game->ray->start_end.x);
	else
		game->ray->min_line_len = (game->ray->movement.y - game->ray->start_end.y);
}

void	get_y_axis(t_ray *ray)
{
	ray->vertical = abs((int)(1080 / ray->min_line_len));
	ray->start = -ray->vertical / 2 + (double)1080 / 2;
	if (ray->start < 0)
		ray->start = 0;
	ray->end = ray->vertical / 2 + (double)1080 / 2;
	if (ray->end >= 1080)
		ray->end = 1080 - 1;
}

void	mlx_put_pixel2(t_game *game, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x >= 1920 || y < 0 || y >= 1080)
		return ;
	dst = game->data_addr + (y * game->size_line + x
			* (game->bpp / 8));
	*(unsigned int *)dst = color;
}

void	draw_backdrop(t_game *game, int *x, int y)
{
	if (game->ray->end < 0)
		game->ray->end = 1080;
	y = game->ray->end;
	while (y < 1080)
	{
		mlx_put_pixel2(game, *x, y, game->floor_color);
		mlx_put_pixel2(game, *x, 1080 - y - 1, game->ceil_color);
		++y;
	}
}
