/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_closed_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofadhel <ofadhel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 17:00:16 by ofadhel           #+#    #+#             */
/*   Updated: 2024/04/14 13:29:54 by ofadhel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	check_space_bottom_left(t_game *game, int y, int x)
{
	if (x < 0 || y < 0 || y >= game->map.height || x >= game->map.width)
		return ;
	else if (game->map.map[y][x] == '1')
		return ;
	else if (game->map.map[y][x] == ' ')
	{
		check_space_bottom_left(game, y, x - 1);
		check_space_bottom_left(game, y - 1, x);
	}
	else
		ft_exit(game, 3);
}

void	check_space_bottom_right(t_game *game, int y, int x)
{
	if (x < 0 || y < 0 || y >= game->map.height || x >= game->map.width)
		return ;
	else if (game->map.map[y][x] == '1')
		return ;
	else if (game->map.map[y][x] == ' ')
	{
		check_space_bottom_right(game, y, x + 1);
		check_space_bottom_right(game, y - 1, x);
	}
	else
		ft_exit(game, 3);
}

void	check_closed_bottom(t_game *game, int y)
{
	int	x;
	int	l;

	l = 0;
	x = 0;
	while (game->map.map[y][x])
	{
		if (game->map.map[y][x] == '1')
			;
		else if (game->map.map[y][x] == ' ')
		{
			check_space_bottom_right(game, y - 1, x);
			check_space_bottom_right(game, y - 1, x + 1);
			check_space_bottom_left(game, y - 1, x - 1);
		}
		else
			ft_exit(game, 3);
		x++;
	}
	check_closed_edges(game);
}
