/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofadhel <ofadhel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 22:38:37 by ofadhel           #+#    #+#             */
/*   Updated: 2024/04/05 16:52:35 by ofadhel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	my_mlx_put_pixel(t_game *game, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x >= game->win_width || y < 0 || y >= game->win_height)
		return ;
	dst = game->mlx.address + (y * game->mlx.size_line + x
			* (game->mlx.bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	fill_wall_texture(t_game *game, int *x, int y)
{
	int	tex_pos;
	int step;
	y = game->draw.start_pos;
	step = 1.0 * 64 / game->draw.line_height;
	tex_pos = (y - game->win_width / 2 + game->draw.line_height / 2) * step;

	if (game->wall.side == NORTH_SOUTH && game->ray.ray_dir_y > 0)
		game->textures.choice = 0;
	if (game->wall.side == NORTH_SOUTH && game->ray.ray_dir_y < 0)
		game->textures.choice = 1;
	if (game->wall.side == EAST_WEST && game->ray.ray_dir_x > 0)
		game->textures.choice = 2;
	if (game->wall.side == EAST_WEST && game->ray.ray_dir_x < 0)
		game->textures.choice = 3;
	while (y <= game->draw.end_pos)
	{
		game->textures.y = (int)tex_pos & (64 - 1);
		tex_pos += step;
		game->textures.colour = (( unsigned int * ) game->textures.stored[game->textures.choice])
			[64 * game->textures.y + game->textures.x];
			mlx_pixel_put(game->mlx.init, game->mlx.win, *x, y, game->textures.colour);
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
		mlx_pixel_put(game->mlx.init, game->mlx.win, *x, y, game->textures.floor);
		mlx_pixel_put(game->mlx.init, game->mlx.win, *x, game->win_height - y, game->textures.ceil);
		y++;
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
			* (double)64);
	if (game->wall.side == NORTH_SOUTH && game->ray.ray_dir_y < 0)
		game->textures.x = 64 - game->textures.x - 1;
	if (game->wall.side == EAST_WEST && game->ray.ray_dir_x > 0)
		game->textures.x = 64 - game->textures.x - 1;
	fill_floor_and_ceiling(game, x, y);
	y += fill_wall_texture(game, x, y);
}
