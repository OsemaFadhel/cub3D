/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofadhel <ofadhel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 18:58:56 by ofadhel           #+#    #+#             */
/*   Updated: 2024/04/24 13:02:31 by ofadhel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	ft_key_press(int keycode, t_game *game)
{
	if (keycode == ESC)
		ft_exit(game, 8);
	if (keycode == W)
		game->player.move_flag_y = 1;
	if (keycode == S)
		game->player.move_flag_y = -1;
	if (keycode == A)
		game->player.move_flag_x = -1;
	if (keycode == D)
		game->player.move_flag_x = 1;
	if (keycode == LEFT)
		game->camera.cam_move = -1;
	if (keycode == RIGHT)
		game->camera.cam_move = 1;
	return (0);
}

int	ft_key_release(int keycode, t_game *game)
{
	if (keycode == W)
		game->player.move_flag_y = 0;
	if (keycode == S)
		game->player.move_flag_y = 0;
	if (keycode == A)
		game->player.move_flag_x = 0;
	if (keycode == D)
		game->player.move_flag_x = 0;
	if (keycode == LEFT)
		game->camera.cam_move = 0;
	if (keycode == RIGHT)
		game->camera.cam_move = 0;
	return (0);
}
