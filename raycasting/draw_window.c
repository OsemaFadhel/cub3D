/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofadhel <ofadhel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 22:38:37 by ofadhel           #+#    #+#             */
/*   Updated: 2024/03/03 23:49:30 by ofadhel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	my_mlx_put_pixel(t_mlx *data, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x >= 1366 || y < 0 || y >= 766)
		return ;
	dst = data->address + (y * data->size_line + x
			* (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	fill_wall_texture(t_game *game, int *x, int y)
{
	y = game->draw.start_pos;
	while (y < game->draw.end_pos)
	{
		game->textures.y = (int)(y * 2 - 1366 + game->draw.line_height)
			* (game->textures.height / 2) / game->draw.line_height;
		if (game->wall.side == NORTH_SOUTH
			&& game->ray.ray_dir_y > 0)
			game->textures.choice = 0;
		if (game->wall.side == NORTH_SOUTH
			&& game->ray.ray_dir_y < 0)
			game->textures.choice = 1;
		if (game->wall.side == EAST_WEST && game->ray.ray_dir_x > 0)
			game->textures.choice = 2;
		if (game->wall.side == EAST_WEST && game->ray.ray_dir_x < 0)
			game->textures.choice = 3;
		game->textures.colour = ((unsigned int *)game->textures.stored[game->textures.choice])
		[game->textures.x + game->textures.y * game->textures.width];
		my_mlx_put_pixel(&game->mlx, *x, y, game->textures.colour);
		++y;
	}
	return (y);
}

void	fill_floor_and_ceiling(t_game *game, int *x, int y)
{
	if (game->draw.end_pos < 0)
		game->draw.end_pos = 1366;
	y = game->draw.end_pos;
	while (y < 769)
	{
		my_mlx_put_pixel(&game->mlx, *x, y, game->textures.floor);
		my_mlx_put_pixel(&game->mlx, *x, 769 - y - 1,
			game->textures.ceil);
		++y;
	}
}

void	draw_columns(t_game *game, int *x)
{
	int	y;

	y = 0;

	if (game->wall.side == EAST_WEST)
	{
		game->textures.wall_x = game->map.player_y
			+ game->wall.perp_wall_dist * game->ray.ray_dir_y;
	}
	else
		game->textures.wall_x = game->map.player_x
			+ game->wall.perp_wall_dist * game->ray.ray_dir_x;
	game->textures.wall_x -= floor(game->textures.wall_x);
	game->textures.x = (int)(game->textures.wall_x
			* (double)game->textures.width);
	if (game->wall.side == NORTH_SOUTH && game->ray.ray_dir_y < 0)
		game->textures.x = game->textures.width - game->textures.x - 1;
	if (game->wall.side == EAST_WEST && game->ray.ray_dir_x > 0)
		game->textures.x = game->textures.width - game->textures.x - 1;

	y += fill_wall_texture(game, x, y);
	fill_floor_and_ceiling(game, x, y);
}
