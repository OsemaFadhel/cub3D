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
		ft_front(game);
	if (keycode == S)
		ft_back(game);
	if (keycode == A)
		ft_left(game);
	if (keycode == D)
		ft_right(game);
	if (keycode == LEFT)
		cam_left(game);
	if (keycode == RIGHT)
		cam_right(game);
	return (0);
}

int	ft_key_release(int	keycode, t_game *game)
{
	if (keycode == W)
		game->player.map_y = 0;
	if (keycode == S)
		game->player.map_y = 0;
	if (keycode == A)
		game->player.map_x = 0;
	if (keycode == D)
		game->player.map_x = 0;
	if (keycode == LEFT){}
	//
	if (keycode == RIGHT){}
	//
	return (0);
}
