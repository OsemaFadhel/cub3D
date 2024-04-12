/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_closed.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofadhel <ofadhel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 16:04:46 by ofadhel           #+#    #+#             */
/*   Updated: 2024/04/12 20:21:47 by ofadhel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	check_space_top_left(t_game *game, int y, int x)
{
	if (x < 0 || y < 0 || y >= game->map.height || x >= game->map.width)
		return ;
	else if (game->map.map[y][x] == '1')
		return ;
	else if (game->map.map[y][x] == ' ')
	{
		check_space_top_left(game, y + 1, x);
		check_space_top_left(game, y, x - 1);
	}
	else
		ft_exit(game, 3);
}

void	check_space_top_right(t_game *game, int y, int x)
{
	if (x < 0 || y < 0 || y >= game->map.height || x >= game->map.width)
		return ;
	else if (game->map.map[y][x] == '1')
		return ;
	else if (game->map.map[y][x] == ' ')
	{
		check_space_top_right(game, y + 1, x);
		check_space_top_right(game, y, x + 1);
	}
	else
		ft_exit(game, 3);
}

void	check_closed_top(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	x = 0;
	while (game->map.map[y][x])
	{
		if (game->map.map[y][x] == '1')
			;
		else if (game->map.map[y][x] == ' ')
		{
			check_space_top_right(game, y + 1, x);
			check_space_top_right(game, y + 1, x + 1);
			check_space_top_left(game, y + 1, x - 1);
		}
		else
			ft_exit(game, 3);
		x++;
	}
	x = 0;
	while (game->map.map[y])
		y++;
}

void	check_closed(t_game *game)
{
	int		i;
	int		j;
	char	**map;
	int		flag;

	i = -1;
	flag = 0;
	while (++i < game->map.height)
	{
		j = -1;
		while (++j < game->map.width)
		{
			if (game->map.map[i][j] == 'S' || game->map.map[i][j] == 'N'
				|| game->map.map[i][j] == 'E' || game->map.map[i][j] == 'W')
			{
				game->map.player_x = i + 0.5;
				game->map.player_y = j + 0.5;
				game->map.player_orientation = game->map.map[i][j];
				flag = 1;
				break ;
			}
		}
	}
	if (!flag)
		ft_exit(game, 2);
	check_closed_top(game);
	check_closed_bottom(game, game->map.height - 1);
	check_closed_edges(game);
}
