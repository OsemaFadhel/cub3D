/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_closed_3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofadhel <ofadhel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 17:05:54 by ofadhel           #+#    #+#             */
/*   Updated: 2024/03/29 17:06:28 by ofadhel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	check_space_left_down(t_game *game, int y, int x)
{
	if (x < 0 || y > game->map.height || x > game->map.width || y < 0)
		return ;
	else if (game->map.map[y][x] == '\0')
		return ;
	else if (game->map.map[y][x] == '1')
		return ;
	else if (game->map.map[y][x] == ' ')
	{
		check_space_left_down(game, y, x + 1);
		check_space_left_down(game, y - 1, x);
	}
	else
		ft_exit(game, 3);
}

void	check_space_left_up(t_game *game, int y, int x)
{
	if (x < 0 || y > game->map.height || x > game->map.width || y < 0)
		return ;
	else if (game->map.map[y][x] == '\0')
		return ;
	else if (game->map.map[y][x] == '1')
		return ;
	else if (game->map.map[y][x] == ' ')
	{
		check_space_left_up(game, y, x + 1);
		check_space_left_up(game, y + 1, x);
	}
	else
		ft_exit(game, 3);
}
