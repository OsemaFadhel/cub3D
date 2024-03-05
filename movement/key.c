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
	if (keycode == W)
		game->player.move_flag_y = 1;
		//ft_front(game);
	if (keycode == S)
		game->player.move_flag_y = -1;
		//ft_back(game);
	if (keycode == A)
		game->player.move_flag_x = -1;
		//ft_left(game);
	if (keycode == D)
		game->player.move_flag_x = 1;
		//ft_right(game);
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
	if (keycode == LEFT){}
	//
	if (keycode == RIGHT){}
	//
	return (0);
}
