#include "include/cub3d.h"

void	calculate_closest_point_to_wall(t_game *game)
{
	if (game->ray->touch_point == 0)
		game->ray->min_line_len = (game->ray->movement.x - game->ray->start_end.x);
	else
		game->ray->min_line_len = (game->ray->movement.y - game->ray->start_end.y);
}

void	calculate_height_line(t_ray *ray)
{
	ray->vertical = abs((int)(1080 / ray->min_line_len));
	ray->start = -ray->vertical / 2 + (double)1080 / 2;
	if (ray->start < 0)
		ray->start = 0;
	ray->end = ray->vertical / 2 + (double)1080 / 2;
	if (ray->end >= 1080)
		ray->end = 1080 - 1;
}

void	my_mlx_put_pixel(t_game *game, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x >= 1920 || y < 0 || y >= 1080)
		return ;
	dst = game->data_addr + (y * game->size_line + x
			* (game->bpp / 8));
	*(unsigned int *)dst = color;
}

void	fill_floor_and_ceiling(t_game *game, int *x_coord, int y)
{
	if (game->ray->end < 0)
		game->ray->end = 1080;
	y = game->ray->end;
	while (y < 1080)
	{
		my_mlx_put_pixel(game, *x_coord, y, game->floor_color);
		my_mlx_put_pixel(game, *x_coord, 1080 - y - 1, game->ceil_color);
		++y;
	}
}

/*int	fill_wall_texture(t_game *game, int *x_coord, int y)
{
	y = game->draw.start_pos;
	while (y < game->ray->end)
	{
		game->textures.y = (int)(y * 2 - 1080 + game->draw.line_height)
			* (game->textures.height / 2) / game->draw.line_height;
		if (game->wall.which_side_hit == NORTH_SOUTH
			&& game->ray.direction_y > 0)
			game->textures.choice = 0;
		if (game->wall.which_side_hit == NORTH_SOUTH
			&& game->ray.direction_y < 0)
			game->textures.choice = 1;
		if (game->wall.which_side_hit == EAST_WEST && game->ray.direction_x > 0)
			game->textures.choice = 2;
		if (game->wall.which_side_hit == EAST_WEST && game->ray.direction_x < 0)
			game->textures.choice = 3;
		game->textures.colour = ((unsigned int *)game
				->textures.stored[game->textures.choice])
		[game->textures.x + game->textures.y * game->textures.width];
		my_mlx_put_pixel(&game->mlx, *x_coord, y, game->textures.colour);
		++y;
	}
	return (y);
}

void	draw_columns(t_game *game, int *x_coord)
{
	int	y;

	y = 0;
	if (game->wall.which_side_hit == EAST_WEST)
	{
		game->textures.wall_x = game->map.player_y
			+ game->wall.shortest_dist_to_wall * ray->dir.y;
	}
	else
		game->textures.wall_x = game->player_dbl.x
			+ game->wall.shortest_dist_to_wall * ray->dir.x;
	game->textures.wall_x -= floor(game->textures.wall_x);
	game->textures.x = (int)(game->textures.wall_x
			* (double)game->textures.width);
	if (game->wall.which_side_hit == NORTH_SOUTH && ray->dir.y < 0)
		game->textures.x = game->textures.width - game->textures.x - 1;
	if (game->wall.which_side_hit == EAST_WEST && ray->dir.x > 0)
		game->textures.x = game->textures.width - game->textures.x - 1;
	y += fill_wall_texture(game, x_coord, y);
	fill_floor_and_ceiling(game, x_coord, y);
}*/