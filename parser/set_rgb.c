/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_rgb.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofadhel <ofadhel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 15:54:45 by ofadhel           #+#    #+#             */
/*   Updated: 2024/02/14 18:03:05 by ofadhel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	set_ceil(t_game *game, char **rgb)
{
	char	*str;
	int		i;

	i = 0;
	rgb = ft_split(game->pars.c, ',');
	while (rgb[i])
		i++;
	if (i != 3)
	{
		//free_matrix(rgb);
		ft_exit(game, 2);
	}
	i = 0;
	while (rgb[i])
	{
		str = ft_strtrim(rgb[i], " ");
		game->pars.ceil[i] = ft_atoi(str);
		if (game->pars.ceil[i] < 0 || game->pars.ceil[i] > 255)
		{
			//free_matrix(rgb);
			ft_exit(game, 2);
		}
		i++;
		free(str);
	}
}

void	set_floor(t_game *game, char **rgb)
{
	char	*str;
	int		i;

	i = 0;
	rgb = ft_split(game->pars.f, ',');
	while (rgb[i])
		i++;
	if (i != 3)
	{
		//free_matrix(rgb);
		ft_exit(game, 2);
	}
	i = 0;
	while (rgb[i])
	{
		str = ft_strtrim(rgb[i], " ");
		game->pars.floor[i] = ft_atoi(str);
		if (game->pars.floor[i] < 0 || game->pars.floor[i] > 255)
		{
			//free_matrix(rgb);
			ft_exit(game, 2);
		}
		i++;
		free(str);
	}
}
int create_rgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void	get_color(t_game *game)
{
	game->ceil_color = create_rgb(0, game->pars.ceil[0], game->pars.ceil[1], game->pars.ceil[2]);
	game->floor_color = create_rgb(0, game->pars.floor[0], game->pars.floor[1], game->pars.floor[2]);
	printf("ceil_color: %d\n", game->ceil_color);
	printf("floor_color: %d\n", game->floor_color);
}

void	set_rgb(t_game *game)
{
	char **rgb;

	set_ceil(game, rgb);
	//free_matrix(rgb);
	set_floor(game, rgb);
	//free_matrix(rgb);
	get_color(game);
}
