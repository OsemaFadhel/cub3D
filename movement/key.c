/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofadhel <ofadhel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 18:58:56 by ofadhel           #+#    #+#             */
/*   Updated: 2024/03/03 22:19:35 by ofadhel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	ft_key(int keycode, t_game *game)
{
	if (keycode == ESC)
		exit(0);
	if (keycode == UP)
		game->player_dbl.y += 10;
	if (keycode == DOWN)
		game->player_dbl.y -= 10;
	if (keycode == LEFT)
		game->player_dbl.x -= 10;
	if (keycode == RIGHT)
		game->player_dbl.x += 10;
	//raycasting(game);
	return (0);
}
