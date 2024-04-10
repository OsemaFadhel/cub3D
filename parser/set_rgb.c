/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_rgb.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofadhel <ofadhel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 15:54:45 by ofadhel           #+#    #+#             */
/*   Updated: 2024/04/10 02:47:39 by ofadhel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	create_rgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void	get_color(t_game *game)
{
	game->textures.ceil = create_rgb(0, game->pars.ceil[0],
			game->pars.ceil[1], game->pars.ceil[2]);
	game->textures.floor = create_rgb(0, game->pars.floor[0],
			game->pars.floor[1], game->pars.floor[2]);
}

void	set_rgb(t_game *game)
{
	set_ceil(game);
	set_floor(game);
	get_color(game);
}
