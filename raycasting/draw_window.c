/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofadhel <ofadhel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 22:38:37 by ofadhel           #+#    #+#             */
/*   Updated: 2024/04/17 16:04:52 by ofadhel          ###   ########.fr       */
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
	double	tex_pos;
	double	step;

	step = 1.0 * 64 / game->draw.line_height;
	tex_pos = (game->draw.start_pos - game->win_height / 2
			+ game->draw.line_height / 2) * step;
	while (y <= game->draw.end_pos)
	{
		game->textures.y = (int)tex_pos & (64 - 1);
		tex_pos += step;
		if (game->wall.side == EAST_WEST && game->ray.ray_dir_y > 0)
			game->textures.choice = 3;
		if (game->wall.side == EAST_WEST && game->ray.ray_dir_y < 0)
			game->textures.choice = 2;
		if (game->wall.side == NORTH_SOUTH && game->ray.ray_dir_x > 0)
			game->textures.choice = 1;
		if (game->wall.side == NORTH_SOUTH && game->ray.ray_dir_x < 0)
			game->textures.choice = 0;
		game->textures.colour = ((unsigned int *)
				game->textures.stored[game->textures.choice])
		[64 * game->textures.y + game->textures.x];
		my_mlx_put_pixel(&game->mlx, *x, y, game->textures.colour);
		y++;
	}
	return (y);
}

void	fill_floor_and_ceiling(t_game *game, int *x, int y)
{
	if (game->draw.end_pos < 0)
		game->draw.end_pos = game->win_height;
	y = game->draw.end_pos + 1;
	while (y < game->win_height)
	{
		my_mlx_put_pixel(&game->mlx, *x, y, game->textures.floor);
		my_mlx_put_pixel(&game->mlx, *x, game->win_height - y - 1,
			game->textures.ceil);
		++y;
	}
}

int	draw_columns(t_game *game, int *x)
{
	int	y;

	y = 0;
	if (game->wall.side == NORTH_SOUTH)
		game->textures.wall_x = game->map.player_y
			+ game->wall.perp_wall_dist * game->ray.ray_dir_y;
	else
		game->textures.wall_x = game->map.player_x
			+ game->wall.perp_wall_dist * game->ray.ray_dir_x;
	game->textures.wall_x -= (int)(game->textures.wall_x);
	game->textures.x = (int)(game->textures.wall_x
			* (double)64);
	game->textures.x = 64 - game->textures.x - 1;
	return (y);
}
