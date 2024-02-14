/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_rgb.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofadhel <ofadhel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 15:54:45 by ofadhel           #+#    #+#             */
/*   Updated: 2024/02/14 15:54:59 by ofadhel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	set_ceil(t_game *game, char **rgb)
{
	char	*str;
	int		i;

	i = 0;
	rgb = ft_split(game->c, ',');
	while (rgb[i])
		i++;
	if (i != 3)
	{
		free(rgb);
		ft_exit(game, 2);
	}
	i = 0;
	while (rgb[i])
	{
		str = ft_strtrim(rgb[i], " ");
		game->ceil[i] = ft_atoi(str);
		if (game->ceil[i] < 0 || game->ceil[i] > 255)
		{
			free(rgb);
			ft_exit(game, 2);
		}
		i++;
	}
}

void	set_floor(t_game *game, char **rgb)
{
	char	*str;
	int		i;

	i = 0;
	rgb = ft_split(game->f, ',');
	while (rgb[i])
		i++;
	if (i != 3)
	{
		free(rgb);
		ft_exit(game, 2);
	}
	i = 0;
	while (rgb[i])
	{
		str = ft_strtrim(rgb[i], " ");
		game->floor[i] = ft_atoi(str);
		if (game->floor[i] < 0 || game->floor[i] > 255)
		{
			free(rgb);
			ft_exit(game, 2);
		}
		i++;
	}
}

void	set_rgb(t_game *game)
{
	char **rgb;

	set_ceil(game, rgb);
	free(rgb);
	set_floor(game, rgb);
	free(rgb);
}
