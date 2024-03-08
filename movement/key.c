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

int	ft_key_press(int keycode, t_game *game)
{
	if (keycode == ESC)
		exit(0);
	if (keycode == W && game->player.move_flag_y < 1)
		game->player.move_flag_y += 1;
	if (keycode == S && game->player.move_flag_y > -1)
		game->player.move_flag_y -= 1;
	if (keycode == A)
		game->player.move_flag_x = -1;
	if (keycode == D)
		game->player.move_flag_x = 1;
	if (keycode == 257)
		game->run = 1;
	if (keycode == LEFT)
		cam_left(game);
	if (keycode == RIGHT)
		cam_right(game);
	return (0);
}

int	ft_key_release(int	keycode, t_game *game)
{
	if (keycode == W)
		game->player.move_flag_y = 0;
	if (keycode == S)
		game->player.move_flag_y = 0;
	if (keycode == A)
		game->player.move_flag_x = 0;
	if (keycode == D)
		game->player.move_flag_x = 0;
	if (keycode == 257)
		game->run = 0;
	if (keycode == LEFT)
		game->player.move_flag_x = 0;
	if (keycode == RIGHT)
		game->player.move_flag_x = 0;
	return (0);
}
