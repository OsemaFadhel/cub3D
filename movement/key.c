/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofadhel <ofadhel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 18:58:56 by ofadhel           #+#    #+#             */
/*   Updated: 2024/03/04 16:55:42 by ofadhel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	ft_key_press(int keycode, t_game *game)
{
	if (keycode == ESC)
		exit(0);
	if (keycode == W)
		game->player.current_square_y += 1;
	if (keycode == S)
		game->player.current_square_y -= 1;
	if (keycode == A)
		game->player.current_square_x -= 1;
	if (keycode == D)
		game->player.current_square_x += 1;
	if (keycode == LEFT){}
	//
	if (keycode == RIGHT){}
	//
	return (0);
}

int	ft_key_release(int	keycode, t_game *game)
{
	if (keycode == W)
		game->player.current_square_y = 0;
	if (keycode == S)
		game->player.current_square_y = 0;
	if (keycode == A)
		game->player.current_square_x = 0;
	if (keycode == D)
		game->player.current_square_x = 0;
	if (keycode == LEFT){}
	//
	if (keycode == RIGHT){}
	//
	return (0);
}
