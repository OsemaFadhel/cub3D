/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofadhel <ofadhel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 22:38:37 by ofadhel           #+#    #+#             */
/*   Updated: 2024/04/04 16:55:38 by ofadhel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	my_mlx_put_pixel(t_game *game, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x >= 1366 || y < 0 || y >= 768)
		return ;
	dst = game->mlx.address + (y * game->mlx.size_line + x
			* (game->mlx.bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	fill_wall_texture(t_game *game, int *x, int y)
{
	y = 0;

	while (y < game->draw.end_pos)
	{
		game->textures.y = (int)(y * 2 - 1366 + game->draw.line_height)
			* (game->textures.height / 2) / game->draw.line_height;
		if (game->wall.side == NORTH_SOUTH && game->ray.ray_dir_y > 0)
			game->textures.choice = 0;
		if (game->wall.side == NORTH_SOUTH && game->ray.ray_dir_y < 0)
			game->textures.choice = 1;
		if (game->wall.side == EAST_WEST && game->ray.ray_dir_x > 0)
			game->textures.choice = 2;
		if (game->wall.side == EAST_WEST && game->ray.ray_dir_x < 0)
			game->textures.choice = 3;
		/*printf("game->textures.choice: %p\n", game->textures.choice);
		printf("game->textures.stored[game->textures.choice]: %p\n", game->textures.stored[game->textures.choice]);
		printf("game->textures.height: %d\n", game->textures.height);
		printf("game->textures.y: %d, %p\n", game->textures.y, game->textures.y);
		printf("game->textures.x: %d, %p\n", game->textures.x, game->textures.x);*/
		game->textures.colour = (( unsigned int * ) game->textures.stored[game->textures.choice])
			[game->textures.height * game->textures.y + game->textures.x];
		mlx_pixel_put(game->mlx.init, game->mlx.win, *x, y, game->textures.colour);
		y++;
	}
	return (y);
}

void	fill_floor_and_ceiling(t_game *game, int *x, int y)
{
	if (game->draw.end_pos < 0)
		game->draw.end_pos = 1366;
	y = game->draw.end_pos;
	while (y < 768)
	{
		mlx_pixel_put(game->mlx.init, game->mlx.win, *x, y, game->textures.floor);
		mlx_pixel_put(game->mlx.init, game->mlx.win, *x, 768 - y, game->textures.ceil);
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
	y += fill_wall_texture(game, x, y);
	fill_floor_and_ceiling(game, x, y);
}
