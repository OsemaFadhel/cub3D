#include "include/cub3d.h"

void	draw_background(t_game *game, int j, int k)
{
	while (k < 1920) //change 1920 with size of the window
	{
		mlx_pixel_put(game->mlx, game->win, k, j, game->ceil_color);
		while (j < 540)
		{
			mlx_pixel_put(game->mlx, game->win, k, j, game->ceil_color);
			j++;
		}
		j = 0;
		k++;
	}
	j = 540;
	k = 0;
	while (k < 1920)
	{
		mlx_pixel_put(game->mlx, game->win, k, j, game->floor_color);
		while (j < 1080)
		{
			mlx_pixel_put(game->mlx, game->win, k, j, game->floor_color);
			j++;
		}
		j = 540;
		k++;
	}
	//now raycasting for the walls
}



void	initialize_ray(t_game *game, int x)
{
	//game->ray->distance = 2 * (double)(x) / (double)1980 - 1;
	game->ray->dir.x = game->ray->vec.x + game->ray->plane.x * game->ray->distance;
	game->ray->dir.y = game->ray->vec.y + game->ray->plane.y * game->ray->distance;
	game->ray->cube.x = (int) game->player_dbl.x;
	game->ray->cube.y = (int) game->player_dbl.y;
}

void	get_x_axis(t_ray *ray)
{
	if (ray->dir.x == 0)
		ray->start_end.x = 1e30;
	else
		ray->start_end.x = fabs(1 / ray->dir.x);
	if (ray->dir.y == 0)
		ray->start_end.y = 1e30;
	else
		ray->start_end.y = fabs(1 / ray->dir.y);
}

void	get_step_size(t_game *game)
{
	if (game->ray->dir.x < 0)
	{
		game->ray->step_size.x = -1;
		game->ray->movement.x = (game->player_dbl.x - game->ray->cube.x) * game->ray->start_end.x;
	}
	else
	{
		game->ray->step_size.x = 1;
		game->ray->movement.x = (game->ray->cube.x + 1.0 - game->player_dbl.x) * game->ray->start_end.x;
	}
	if (game->ray->dir.y < 0)
	{
		game->ray->step_size.y = -1;
		game->ray->movement.y = (game->player_dbl.y - game->ray->cube.y) * game->ray->start_end.y;
	}
	else
	{
		game->ray->step_size.y = 1;
		game->ray->movement.y = (game->ray->cube.y + 1.0 - game->player_dbl.y) * game->ray->start_end.y;
	}
}

void	lodev_algorithm(t_game *game)
{
	game->ray->hit = 0;
	while (game->ray->hit == 0)
	{
		if (game->ray->movement.x < game->ray->movement.y)
		{
			game->ray->movement.x += game->ray->start_end.x;
			game->ray->cube.x += game->ray->step_size.x;
			game->ray->touch_point = 0;
		}
		else
		{
			game->ray->movement.y += game->ray->start_end.y;
			game->ray->cube.y += game->ray->step_size.y;
			game->ray->touch_point = 1;
		}
		if (game->map[game->ray->cube.x][game->ray->cube.y] == '1')
		{
			game->ray->hit = 1;
		}
	}
}

void	raycasting(t_game *game)
{
	int			x;

	x = 0;
	initialize_ray(game, x);
	while (x <= 1980)
	{
		initialize_ray(game, x);
		get_x_axis(game->ray);
		get_step_size(game);
		lodev_algorithm(game);
		get_minlen(game);
		get_y_axis(game->ray);
		draw_backdrop(game, &x, 0);
		++x;
	}

}
