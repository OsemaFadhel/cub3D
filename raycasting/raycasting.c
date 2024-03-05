#include "../include/cub3d.h"

void	ray_pos_and_dir(t_game *game, int *x)
{
	game->camera.current_x = 2 * (double)(*x) / (double)1366 - 1;
	game->ray.ray_dir_x = game->player.director_vector_x
		+ game->camera.plane_x * game->camera.current_x;
	game->ray.ray_dir_y = game->player.director_vector_y
		+ game->camera.plane_y * game->camera.current_x;
	game->player.map_x = (int) game->map.player_x;
	game->player.map_y = (int) game->map.player_y;
}

void	ray_length(t_ray *ray)//length of ray from one x or y-side to next x or y-side
{
	if (ray->ray_dir_x == 0)
		ray->delta_dist_x = 1e30;
	else
		ray->delta_dist_x = fabs(1 / ray->ray_dir_x);
	if (ray->ray_dir_y == 0)
		ray->delta_dist_y = 1e30;
	else
		ray->delta_dist_y = fabs(1 / ray->ray_dir_y);
}

void	step_and_side_distance(t_player *player, t_ray *ray, t_map *map)//calculate step and initial sideDist
{
	if (ray->ray_dir_x < 0)
	{
		ray->step_x = -1;
		ray->side_dist_x = (map->player_x
				- player->map_x) * ray->delta_dist_x;
	}
	else
	{
		ray->step_x = 1;
		ray->side_dist_x = (player->map_x + 1.0
				- map->player_x) * ray->delta_dist_x;
	}
	if (ray->ray_dir_y < 0)
	{
		ray->step_y = -1;
		ray->side_dist_y = (map->player_y
				- player->map_y) * ray->delta_dist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_dist_y = (player->map_y + 1.0
				- map->player_y) * ray->delta_dist_y;
	}
}

void	dda_algo(t_ray *ray, t_player *player,
	t_wall *wall, t_map *map)
{
	wall->hit = 0;
	while (wall->hit == 0)
	{
		if (ray->side_dist_x < ray->side_dist_y)
		{
			ray->side_dist_x += ray->delta_dist_x;
			player->map_x += ray->step_x;
			wall->side = 0;
		}
		else
		{
			ray->side_dist_y += ray->delta_dist_y;
			player->map_y += ray->step_y;
			wall->side = 1;
		}
		if (map->map[player->map_x][player->map_y] == '1')
		{
			wall->hit = 1;
		}
	}
}

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
		draw_columns(game, &x); // draw_window.c
		++x;
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
