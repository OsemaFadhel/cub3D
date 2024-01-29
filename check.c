/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofadhel <ofadhel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 17:27:31 by ofadhel           #+#    #+#             */
/*   Updated: 2023/04/24 22:22:39 by ofadhel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	free_map_check(t_check *check)
{
	int	i;

	i = 0;
	while (check->map[i])
	{
		free(check->map[i]);
		i++;
	}
	free(check->map);
}

void	checks(t_check *check, t_game *game)
{
	if (check_walls(check, check->map_height, check->map_width) == 0)
	{
		ft_printf("ERROR, map walls\n");
		free_map(game);
		free_map_check(check);
		exit(1);
	}
	check_map(check, game);
	if (check->player != 1 || check->coin == 0 || check->exit != 1)
	{
		ft_printf("ERROR, map\n");
		free_map(game);
		free_map_check(check);
		exit(1);
	}
	free_map_check(check);
}

int	check_walls(t_check *check, int height, int width)
{
	int	i;

	i = 0;
	while (check->map[0][i])
	{
		if (check->map[0][i] != '1' || check->map[height - 1][i] != '1')
		{
			return (0);
		}
		i++;
	}
	i = 0;
	while (check->map[i])
	{
		if (check->map[i][0] != '1' || check->map[i][width - 1] != '1')
		{
			return (0);
		}
		i++;
	}
	return (1);
}

void	check_map(t_check *check, t_game *game)
{
	int	height;
	int	width;

	height = 0;
	while (game->map[height])
	{
		width = 0;
		while (game->map[height][width])
		{
			count_sprites(check, game, height, width);
			width++;
		}
		height++;
	}
}

void	count_sprites(t_check *check, t_game *game, int height, int width)
{
	if (check->map[height][width] == '0')
		return ;
	else if (check->map[height][width] == '1')
		return ;
	else if (check->map[height][width] == 'P')
		check->player++;
	else if (check->map[height][width] == 'C')
	{
		game->coin_count++;
		check->coin++;
	}
	else if (check->map[height][width] == 'E')
		check->exit++;
	else if (check->map[height][width] == 'N')
		return ;
	return ;
}
