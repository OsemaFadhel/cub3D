#include "include/cub3d.h"

int	ft_max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

void	ray_casting(t_game *game, t_ray *ray)
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
}


void	initialize_ray(t_game *game, t_ray *ray, double angle)
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
}

void	ft_put_pixel(t_game *game, int x, int y, int color)
{
	int	i;

	if (x >= 0 && x < 1280 && y >= 0 && y < 720)
	{
		i = (x * game->bpp / 8) + (y * game->size_line);
		game->data_addr[i] = color;
		game->data_addr[++i] = color >> 8;
		game->data_addr[++i] = color >> 16;
	}
}

void	draw_background(t_game *game, int j, int k)
{
	while (k < 1920)
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

}

/*int main()
{
	t_game game;
	game.player_axis.x = 2.0;
	game.player_axis.y = 2.0;

	t_ray ray;

	double angles[] = {0.0, M_PI / 4.0, M_PI / 2.0, 3.0 * M_PI / 4.0};

	for (int i = 0; i < sizeof(angles) / sizeof(angles[0]); ++i)
	{
		double angle = angles[i];
		double len = raylen(&game, &ray, angle);
	}
	return 0;
}*/
