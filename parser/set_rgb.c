/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_rgb.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofadhel <ofadhel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 15:54:45 by ofadhel           #+#    #+#             */
/*   Updated: 2024/04/10 00:22:38 by ofadhel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	set_ceil(t_game *game, char **rgb)
{
	char	*str;
	int		i;

	i = -1;
	rgb = ft_split(game->pars.c, ',');
	while (rgb[++i])
		;
	if (i != 3)
	{
		free_matrix(rgb);
		ft_exit(game, 2);
	}
	i = -1;
	while (rgb[++i])
	{
		str = ft_strtrim(rgb[i], " ");
		if (*str == '\0')
			ft_exit(game, 2);
		game->pars.ceil[i] = ft_atoi(str);
		if (game->pars.ceil[i] < 0 || game->pars.ceil[i] > 255)
		{
			free_matrix(rgb);
			ft_exit(game, 2);
		}
		free(str);
	}
	free_matrix(rgb);
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
		free_matrix(rgb);
		ft_exit(game, 2);
	}
	i = -1;
	while (rgb[++i])
	{
		str = ft_strtrim(rgb[i], " ");
		if (*str == '\0')
			ft_exit(game, 2);
		game->pars.floor[i] = ft_atoi(str);
		if (game->pars.floor[i] < 0 || game->pars.floor[i] > 255)
		{
			free_matrix(rgb);
			ft_exit(game, 2);
		}
		free(str);
	}
	free_matrix(rgb);
}

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
	char	**rgb;

	set_ceil(game, rgb);
	set_floor(game, rgb);
	get_color(game);
}
