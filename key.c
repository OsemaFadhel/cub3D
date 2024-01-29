/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofadhel <ofadhel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 18:58:56 by ofadhel           #+#    #+#             */
/*   Updated: 2024/01/29 12:11:26 by ofadhel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int	key(int keycode, t_game *game)
{
	if (keycode == ESC)
		close_game(game);
	if (keycode == UP)
		game->moves += move_up(game);
	if (keycode == DOWN)
		game->moves += move_down(game);
	if (keycode == LEFT)
		game->moves += move_left(game);
	if (keycode == RIGHT)
		game->moves += move_right(game);
	set_win(game);
	return (0);
}

