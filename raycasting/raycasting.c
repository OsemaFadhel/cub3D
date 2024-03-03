#include "../include/cub3d.h"

void	instantiate_ray(t_game *game, int *x)
{
	game->camera.current_x = 2 * (double)(*x) / (double)1920 - 1;
	game->ray.direction_x = game->player.director_vector_x
		+ game->camera.plane_x * game->camera.current_x;
	game->ray.direction_y = game->player.director_vector_y
		+ game->camera.plane_y * game->camera.current_x;
	game->player.current_square_x = (int) game->map.player_x;
	game->player.current_square_y = (int) game->map.player_y;
}

void	calculate_length_to_next_x(t_ray *ray)
{
	if (ray->direction_x == 0)
		ray->distance_to_next_x = 1e30;
	else
		ray->distance_to_next_x = fabs(1 / ray->direction_x);
	if (ray->direction_y == 0)
		ray->distance_to_next_y = 1e30;
	else
		ray->distance_to_next_y = fabs(1 / ray->direction_y);
}

void	calculate_step_and_side_dist(t_player *player, t_ray *ray, t_map *map)
{
	if (ray->direction_x < 0)
	{
		ray->step_in_x = -1;
		ray->move_to_next_x = (map->player_x
				- player->current_square_x) * ray->distance_to_next_x;
	}
	else
	{
		ray->step_in_x = 1;
		ray->move_to_next_x = (player->current_square_x + 1.0
				- map->player_x) * ray->distance_to_next_x;
	}
	if (ray->direction_y < 0)
	{
		ray->step_in_y = -1;
		ray->move_to_next_y = (map->player_y
				- player->current_square_y) * ray->distance_to_next_y;
	}
	else
	{
		ray->step_in_y = 1;
		ray->move_to_next_y = (player->current_square_y + 1.0
				- map->player_y) * ray->distance_to_next_y;
	}
}

void	perform_dda_algorithm(t_ray *ray, t_player *player,
	t_wall *wall, t_map *map)
{
	wall->is_hit = false;
	while (wall->is_hit == false)
	{
		if (ray->move_to_next_x < ray->move_to_next_y)
		{
			ray->move_to_next_x += ray->distance_to_next_x;
			player->current_square_x += ray->step_in_x;
			wall->which_side_hit = EAST_WEST;
		}
		else
		{
			ray->move_to_next_y += ray->distance_to_next_y;
			player->current_square_y += ray->step_in_y;
			wall->which_side_hit = NORTH_SOUTH;
		}
		if (map->map[player->current_square_x][player->current_square_y] == '1')
		{
			wall->is_hit = true;
		}
	}
}

void	calculate_closest_point_to_wall(t_wall *wall, t_ray *ray)
{
	if (wall->which_side_hit == EAST_WEST)
		wall->shortest_dist_to_wall = (ray->move_to_next_x
				- ray->distance_to_next_x);
	else
		wall->shortest_dist_to_wall = (ray->move_to_next_y
				- ray->distance_to_next_y);
}

void	calculate_height_line(t_wall *wall, t_draw *draw)
{
	draw->line_height = abs((int)(1080 / wall->shortest_dist_to_wall));
	draw->start_pos = -draw->line_height / 2 + (double)1080 / 2;
	if (draw->start_pos < 0)
		draw->start_pos = 0;
	draw->end_pos = draw->line_height / 2 + (double)1080 / 2;
	if (draw->end_pos >= 1080)
		draw->end_pos = 1080 - 1;
}

void	raycasting(t_game *game)
{
	int			x_coord;

	x_coord = 0;
	while (x_coord <= 1920)
	{
		instantiate_ray(game, &x_coord);
		calculate_length_to_next_x(&game->ray);
		calculate_step_and_side_dist(&game->player, &game->ray, &game->map);
		perform_dda_algorithm(&game->ray, &game->player,
			&game->wall, &game->map);
		calculate_closest_point_to_wall(&game->wall, &game->ray);
		calculate_height_line(&game->wall, &game->draw);
		draw_columns(game, &x_coord); // draw_window.c
		++x_coord;
	}
}

void	render(t_game *game)
{
	raycasting(game);
	mlx_put_image_to_window(&game->mlx.init, game->mlx.win,
		game->mlx.img, 0, 0);
}

int	game_loop(t_game *game)
{
	render(game);
	return (0);
}
