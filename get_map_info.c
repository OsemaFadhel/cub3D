/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_info.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofadhel <ofadhel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 17:24:10 by ofadhel           #+#    #+#             */
/*   Updated: 2023/04/25 16:36:52 by ofadhel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	init(t_game *game, t_check *check)
{
	check->map_height = 0;
	check->map_width = 0;
	check->player = 0;
	check->exit = 0;
	check->coin = 0;
	game->moves = 0;
	game->player_x = 0;
	game->player_y = 0;
	game->coin_count = 0;
	game->start = 0;
	game->coin = 0;
	game->floor = 0;
	game->exit = 0;
	game->player = 0;
	game->map_width = 0;
	game->map_height = 0;
	game->enemy_move = 0;
}

void	map_size(t_game *game, t_check *check)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (game->map[i])
	{
		i++;
	}
	while (game->map[0][j])
	{
		j++;
	}
	if (i == j)
	{
		ft_printf("Error : Map must be a rectangular\n");
		free_map_check(check);
		free_map(game);
		exit(1);
	}
	game->map_width = j * 64;
	game->map_height = i * 64;
	check->map_width = j;
	check->map_height = i;
}

void	free_map(t_game *game)
{
	int	i;

	i = 0;
	while (game->map[i])
	{
		free(game->map[i]);
		i++;
	}
	i = 0;
	free(game->map);
}
