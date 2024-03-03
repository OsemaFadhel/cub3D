/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofadhel <ofadhel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 18:58:56 by ofadhel           #+#    #+#             */
/*   Updated: 2024/03/04 00:01:14 by ofadhel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	ft_key(int keycode, t_game *game)
{
	if (keycode == ESC)
		exit(0);
	if (keycode == W)
		game->player.current_square_y -= 1;
	if (keycode == S)
		game->player.current_square_y += 1;
	if (keycode == A)
		game->player.current_square_x -= 1;
	if (keycode == D)
		game->player.current_square_x += 1;
	if (keycode == LEFT)
	{
		game->player.director_vector_x = game->player.director_vector_x
			* cos(0.1) - game->player.director_vector_y * sin(0.1);
		game->player.director_vector_y = game->player.director_vector_x
			* sin(0.1) + game->player.director_vector_y * cos(0.1);
	}
	if (keycode == RIGHT)
	{
		game->player.director_vector_x = game->player.director_vector_x
			* cos(-0.1) - game->player.director_vector_y * sin(-0.1);
		game->player.director_vector_y = game->player.director_vector_x
			* sin(-0.1) + game->player.director_vector_y * cos(-0.1);
	}
	game_loop(game);
	return (0);
}
