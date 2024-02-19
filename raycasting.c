#include "include/cub3d.h"

int	ft_max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

/*void	ray_casting(t_game *game, t_ray *ray)
{
	double	max;  ///maximum distance, returns the largest from the width or height of the map

	max = (double)ft_max(game->map_axis->y, game->map_axis->x);
	while (!ray->hit && ray->distance < max)
	{
		if (ray->len.x < ray->len.y)
		{
			ray->map_check.x += ray->step.x;
			ray->distance = ray->len.x;
			ray->vertical = 1;
			ray->len.x += ray->step_size.x;
		}
		else
		{
			ray->map_check.y += ray->step.y;
			ray->distance = ray->len.y;
			ray->vertical = 0;
			ray->len.y += ray->step_size.y;
		}
		if (ray->map_check.x >= 0 && ray->map_check.x < game->map_axis->x && ray->map_check.y >= 0
			&& ray->map_check.y < game->map_axis->y && game->map[ray->map_check.y][ray->map_check.x] == '1')
				ray->hit = 1;
	}
}

double	raylen(t_game *game, t_ray *ray, double angle) //per ottenere il len del ray (lana del ray) finche non tocca il muro
{
	double	len;

	initialize_ray(game, ray, angle);
	ray_casting(game, ray);
	if (ray->hit)
	{
		ray->touch_point.x = ray->dir.x * ray->distance + ray->start.x;
		ray->touch_point.y = ray->dir.y * ray->distance + ray->start.y;
	}
	len = sqrt(pow(ray->touch_point.x - ray->start.x, 2) + pow(ray->touch_point.y - ray->start.y, 2));
	return (len);
}*/


/*void	initialize_ray(t_game *game, t_ray *ray, double angle)
{
	ray->hit = 0;
	ray->vertical = 0;
	ray->dir.x = cos(angle);
	ray->dir.y = sin(angle);
	ray->step_size.x = sqrt(1.0 + pow(ray->dir.y / ray->dir.x, 2));
	ray->step_size.y = sqrt(1.0 + pow(ray->dir.x / ray->dir.y, 2));
	ray->start = game->player_axis;
	ray->map_check.x = (int)ray->start.x;
	ray->map_check.y = (int)ray->start.y;
	if (ray->dir.x < 0)
		ray->len.x = (ray->start.x - (double)ray->map_check.x) * ray->step_size.x;
	else
		ray->len.x = ((double)(ray->map_check.x + 1) - ray->start.x) * ray->step_size.x;
	ray->step.x = 1 - (ray->dir.x < 0) * 2;
	if (ray->dir.y < 0)
		ray->len.y = (ray->start.y - (double)ray->map_check.y) * ray->step_size.y;
	else
		ray->len.y = ((double)(ray->map_check.y + 1) - ray->start.y) * ray->step_size.y;
	ray->step.y = 1 - (ray->dir.y < 0) * 2;
}*/

void	initialize_ray(t_game *game, int x, t_ray *ray)
{
	// Calculate the ray's direction in camera space
	double camera_x = 2 * x / (double)game->win_width - 1;
	ray->dir.x = game->pars.dir.x + game->pars.plane.x * camera_x;
	ray->dir.y = game->pars.dir.y + game->pars.plane.y * camera_x;

	// Map position of the player (initial position of the ray)
	ray->touch_point.x = (int)game->player_axis.x;
	ray->touch_point.y = (int)game->player_axis.y;

	// Length of the ray from one x or y-side to the next x or y-side
	ray->len.x = sqrt(1 + (ray->dir.y * ray->dir.y) / (ray->dir.x * ray->dir.x));
	ray->len.y = sqrt(1 + (ray->dir.x * ray->dir.x) / (ray->dir.y * ray->dir.y));

	// Calculate the step and initial values for DDA
	if (ray->dir.x < 0)
	{
		ray->step.x = -1;
		ray->step_size.x = (game->player_axis.x - ray->touch_point.x) * ray->len.x;
	}
	else
	{
		ray->step.x = 1;
		ray->step_size.x = (ray->touch_point.x + 1.0 - game->player_axis.x) * ray->len.x;
	}

	if (ray->dir.y < 0)
	{
		ray->step.y = -1;
		ray->step_size.y = (game->player_axis.y - ray->touch_point.y) * ray->len.y;
	}
	else
	{
		ray->step.y = 1;
		ray->step_size.y = (ray->touch_point.y + 1.0 - game->player_axis.y) * ray->len.y;
	}

	// Initialize other ray parameters
	ray->hit = 0;
	ray->vertical = 0;
	ray->distance = 0;
	ray->line_len = 0;
}

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

void	draw_walls(t_game *game, int x, t_ray *ray)
{
	int		wall_height;
	int		draw_start;
	int		draw_end;

	// Calculate the height of the wall on the screen
	wall_height = (int)(game->win_height / ray->distance);

	// Calculate the drawing boundaries on the screen
	draw_start = -wall_height / 2 + game->win_height / 2;
	draw_end = wall_height / 2 + game->win_height / 2;

	// Ensure the drawing boundaries are within the screen limits
	draw_start = (draw_start < 0) ? 0 : draw_start;
	draw_end = (draw_end >= game->win_height) ? game->win_height - 1 : draw_end;

	// Draw the wall line
	while (draw_start < draw_end)
	{
		mlx_pixel_put(game->mlx, game->win, x, draw_start, 0xFFFFFF);
		draw_start++;
	}
}

void	cast_ray(t_game *game, int x, t_ray *ray)
{
	printf("enters cast ray");
	initialize_ray(game, x, ray);  // Initialize ray parameters based on player's position and direction

	while (ray->hit == 0)
	{
		// Perform DDA (Digital Differential Analyzer) steps to find the intersection with a wall
		if (ray->len.x < ray->len.y)
		{
			ray->len.x += ray->step_size.x;
			ray->touch_point.x += ray->step.x;
			ray->vertical = 0;
		}
		else
		{
			ray->len.y += ray->step_size.y;
			ray->touch_point.y += ray->step.y;
			ray->vertical = 1;
		}

		// Check if the ray hit a wall
		if (game->map_array[(int)ray->touch_point.y][(int)ray->touch_point.x] == '1')
			ray->hit = 1;
	}

	// Calculate distance to the wall
	ray->distance = (ray->vertical) ? fabs((ray->touch_point.y - game->player_axis.y) / ray->dir.y)
									 : fabs((ray->touch_point.x - game->player_axis.x) / ray->dir.x);

	// Draw the wall on the screen
	draw_walls(game, x, ray);
}

void	raycasting(t_game *game)
{
	printf("enters raycasting function");
	int		x;
	t_ray	ray;

	x = 0;
	while (x < game->win_width)
	{
		cast_ray(game, x, &ray);
		x++;
	}
}

