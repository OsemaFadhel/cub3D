#include "include/cub3d.h"

void	init(t_game *game)
{
	game->map.map = 0;
	game->map.player_orientation = 0;
	game->map.start_line = 0;
	game->map.x = 0;
	game->map.y = 0;
	game->map.player_found = 0;
	game->map.player_x = 0;
	game->map.player_y = 0;
	game->map.player_patch = 0;
	game->map.map_error = 0;
	game->map.floor = 0;
	game->map.ceiling = 0;
	game->player.current_square_x = 0;
	game->player.current_square_y = 0;
	game->camera.current_x = 0;
	game->ray.direction_x = 0;
	game->ray.direction_y = 0;
	game->ray.move_to_next_x = 0;
	game->ray.move_to_next_y = 0;
	game->ray.distance_to_next_x = 0;
	game->ray.distance_to_next_y = 0;
	game->ray.step_in_x = 0;
	game->ray.step_in_y = 0;
	game->wall.shortest_dist_to_wall = 0;
	game->wall.is_hit = 0;
	game->wall.which_side_hit = 0;
	game->draw.end_pos = 0;
	game->draw.start_pos = 0;
	game->draw.line_height = 0;
	game->textures.stored[0] = NULL;
	game->textures.stored[1] = NULL;
	game->textures.stored[2] = NULL;
	game->textures.stored[3] = NULL;
	game->textures.no = NULL;
	game->textures.so = NULL;
	game->textures.we = NULL;
	game->textures.ea = NULL;
	game->textures.choice = 0;
	game->textures.colour = 0;
	game->textures.f = 0;
	game->textures.c = 0;
	game->textures.x = 0;
	game->textures.y = 0;
	game->textures.height = 64;
	game->textures.width = 64;
	game->textures.wall_x = 0;
}

static void	init_camera_position_ns(t_player *player, t_map *map,
	t_camera *camera)
{
	if (map->player_orientation == 'N')
	{
		player->director_vector_x = -1;
		player->director_vector_y = 0;
		camera->plane_x = 0;
		camera->plane_y = 0.66;
	}
	if (map->player_orientation == 'S')
	{
		player->director_vector_x = 1;
		player->director_vector_y = 0;
		camera->plane_x = 0;
		camera->plane_y = -0.66;
	}
}

static void	init_camera_position_ew(t_player *player, t_map *map,
	t_camera *camera)
{
	if (map->player_orientation == 'E')
	{
		player->director_vector_x = 0;
		player->director_vector_y = 1;
		camera->plane_x = 0.66;
		camera->plane_y = 0;
	}
	if (map->player_orientation == 'W')
	{
		player->director_vector_x = 0;
		player->director_vector_y = -1;
		camera->plane_x = -0.66;
		camera->plane_y = 0;
	}
}

void	init_camera_position(t_player *player, t_map *map, t_camera *camera)
{
	if (map->player_orientation == 'N' || map->player_orientation == 'S')
		init_camera_position_ns(player, map, camera);
	else if (map->player_orientation == 'E' || map->player_orientation == 'W')
		init_camera_position_ew(player, map, camera);
}

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

void	calculate_closest_point_to_wall(t_wall *wall, t_ray *ray)
{
	if (wall->which_side_hit == EAST_WEST)
		wall->shortest_dist_to_wall = (ray->move_to_next_x
				- ray->distance_to_next_x);
	else
		wall->shortest_dist_to_wall = (ray->move_to_next_y
				- ray->distance_to_next_y);
}

void	my_mlx_put_pixel(t_mlx *data, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x >= 1920 || y < 0 || y >= 1080)
		return ;
	dst = data->address + (y * data->line_length + x
			* (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	fill_wall_texture(t_game *game, int *x_coord, int y)
{
	y = game->draw.start_pos;
	while (y < game->draw.end_pos)
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

void	fill_floor_and_ceiling(t_game *game, int *x_coord, int y)
{
	if (game->draw.end_pos < 0)
		game->draw.end_pos = 1080;
	y = game->draw.end_pos;
	while (y < 1080)
	{
		my_mlx_put_pixel(&game->mlx, *x_coord, y, game->map.floor);
		my_mlx_put_pixel(&game->mlx, *x_coord, 1080 - y - 1,
			game->map.ceiling);
		++y;
	}
}

void	draw_columns(t_game *game, int *x_coord)
{
	int	y;

	y = 0;

	y += fill_wall_texture(game, x_coord, y);
	fill_floor_and_ceiling(game, x_coord, y);
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
		draw_columns(game, &x_coord);
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

int	run_mlx(t_mlx *mlx, t_game *game)
{
	mlx_loop_hook(mlx->init, game_loop, game);
	mlx_put_image_to_window(mlx->init, mlx->win, mlx->img, 0, 0);
	mlx_hook(game->mlx.win, 17, 0, ft_exit, &game);
	mlx_key_hook(game->mlx.win, key, &game);
	mlx_loop(mlx->init);
	return (1);
}

static void	check_size(int *width, int *height)
{
	// if (*width != 64)
	// 	error(0, "Invalid texture width\n", 0);
	// if (*height != 64)
	// 	error(0, "Invalid texture height\n", 0);
}

static void	to_xpm_suite(t_game *game)
{
	int	x;
	int	y;
	int	z;

	game->textures.stored[0] = mlx_get_data_addr(game->textures.wall_no,
			&x, &y, &z);
	// if (!game->textures.stored[0])
	// 	error(0, "MLX ERROR\n", 0);
	game->textures.stored[1] = mlx_get_data_addr(game->textures.wall_so,
			&x, &y, &z);
	// if (!game->textures.stored[1])
	// 	error(0, "MLX ERROR\n", 0);
	game->textures.stored[2] = mlx_get_data_addr(game->textures.wall_ea,
			&x, &y, &z);
	// if (!game->textures.stored[2])
	// 	error(0, "MLX ERROR\n", 0);
	game->textures.stored[3] = mlx_get_data_addr(game->textures.wall_we,
			&x, &y, &z);
	// if (!game->textures.stored[3])
	// 	error(0, "MLX ERROR\n", 0);
}

void	to_xpm(t_mlx *mlx, t_game *game)
{
	game->textures.wall_ea = mlx_xpm_file_to_image(mlx->init, game->textures.ea,
			&game->textures.width, &game->textures.height);
	check_size(&game->textures.width, &game->textures.height);
	game->textures.wall_no = mlx_xpm_file_to_image(mlx->init, game->textures.no,
			&game->textures.width, &game->textures.height);
	check_size(&game->textures.width, &game->textures.height);
	game->textures.wall_so = mlx_xpm_file_to_image(mlx->init, game->textures.so,
			&game->textures.width, &game->textures.height);
	check_size(&game->textures.width, &game->textures.height);
	game->textures.wall_we = mlx_xpm_file_to_image(mlx->init, game->textures.we,
			&game->textures.width, &game->textures.height);
	check_size(&game->textures.width, &game->textures.height);
	to_xpm_suite(game);
}

int	init_mlx(t_mlx *mlx, t_game *game)
{
	mlx->init = mlx_init();
	// if (!mlx->init)
	// 	error(0, "MLX ERROR\n", 0);
	mlx->win = mlx_new_window(mlx->init, 1920, 1080, "cub3d");
	// if (!mlx->win)
	// 	error(0, "MLX ERROR\n", 0);
	mlx->img = mlx_new_image(mlx->init, 1920, 1080);
	// if (!mlx->img)
	// 	error(0, "MLX ERROR\n", 0);
	mlx->address = mlx_get_data_addr(mlx->img, &mlx->bits_per_pixel,
			&mlx->line_length, &mlx->endian);
	// if (!mlx->address)
	// 	error(0, "MLX ERROR\n", 0);
	//to_xpm(mlx, game);
	run_mlx(mlx, game);
	return (0);
}

void	init_struc(char **av, t_game *game)
{
	init(game);
	parser(av, game);
	init_camera_position(&game->player, &game->map, &game->camera);
	init_mlx(&game->mlx, game);
}


int	main(int ac, char **av)
{
	t_game	game;

	if (ac != 2)
	{
		printf("Error: no map or too many arguments\n");
		return (1);
	}
	init_struc(av, &game);
	return (0);
}
