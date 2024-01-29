/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_img.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofadhel <ofadhel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 17:39:35 by ofadhel           #+#    #+#             */
/*   Updated: 2023/04/25 16:26:17 by ofadhel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	xpm_img(t_game *game)
{
	game->floor = mlx_xpm_file_to_image(game->mlx, "img/floor.xpm",
			&game->map_width, &game->map_height);
	game->wall = mlx_xpm_file_to_image(game->mlx, "img/wall.xpm",
			&game->map_width, &game->map_height);
	game->player = mlx_xpm_file_to_image(game->mlx, "img/player.xpm",
			&game->map_width, &game->map_height);
	game->exit = mlx_xpm_file_to_image(game->mlx, "img/exit.xpm",
			&game->map_width, &game->map_height);
	game->coin = mlx_xpm_file_to_image(game->mlx, "img/coin.xpm",
			&game->map_width, &game->map_height);
	game->enemy = mlx_xpm_file_to_image(game->mlx, "./img/enemy.xpm",
			&game->map_width, &game->map_height);
	game->enemy_1 = mlx_xpm_file_to_image(game->mlx, "./img/enemy1.xpm",
			&game->map_width, &game->map_height);
}

void	put_img(t_game *game, int height, int width)
{
	if (game->map[height][width] == '1')
	{
		mlx_put_image_to_window(game->mlx, game->win, game->wall,
			width * 64, height * 64);
	}
	if (game->map[height][width] == '0')
	{
		mlx_put_image_to_window(game->mlx, game->win, game->floor,
			width * 64, height * 64);
	}
	if (game->map[height][width] == 'P')
	{
		mlx_put_image_to_window(game->mlx, game->win, game->player,
			width * 64, height * 64);
		game->player_x = width;
		game->player_y = height;
	}
	if (game->map[height][width] == 'C')
	{
		mlx_put_image_to_window(game->mlx, game->win, game->coin,
			width * 64, height * 64);
	}
	if (game->map[height][width] == 'E')
		put_exit(game, height, width);
}

void	put_exit(t_game *game, int height, int width)
{
	mlx_put_image_to_window(game->mlx, game->win, game->exit,
		width * 64, height * 64);
}

void	put_enemy(t_game *game, int height, int width)
{
	if (game->map[height][width] == 'N' && game->enemy_move == 0)
	{
		mlx_put_image_to_window(game->mlx, game->win, game->enemy,
			width * 64, height * 64);
		game->enemy_move = 1;
	}
	if (game->map[height][width] == 'N' && game->enemy_move == 1)
	{
		mlx_put_image_to_window(game->mlx, game->win, game->enemy_1,
			width * 64, height * 64);
		game->enemy_move = 0;
	}
}

void	set_win(t_game *game)
{
	int		height;
	int		width;
	char	*moves;

	moves = ft_itoa(game->moves);
	height = 0;
	while (game->map[height])
	{
		width = 0;
		while (game->map[height][width])
		{
			put_img(game, height, width);
			put_enemy(game, height, width);
			width++;
		}
		height++;
	}
	mlx_string_put(game->mlx, game->win, 15, 2, 12144232, moves);
}
