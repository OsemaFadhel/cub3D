/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_rgb_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofadhel <ofadhel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 02:47:16 by ofadhel           #+#    #+#             */
/*   Updated: 2024/04/17 15:54:00 by ofadhel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	set_ceil2(t_game *game, char **rgb, char *str)
{
	int	i;

	i = -1;
	while (rgb[++i])
	{
		str = ft_strtrim(rgb[i], " ");
		if (*str == '\0')
		{
			free_matrix(rgb);
			free(str);
			ft_exit(game, 2);
		}
		game->pars.ceil[i] = ft_atoi(str);
		if (game->pars.ceil[i] < 0 || game->pars.ceil[i] > 255)
		{
			free_matrix(rgb);
			free(str);
			ft_exit(game, 2);
		}
		free(str);
	}
}

void	set_ceil(t_game *game)
{
	char	*str;
	char	**rgb;
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
	set_ceil2(game, rgb, str);
	free_matrix(rgb);
}

void	set_floor2(t_game *game, char **rgb, char *str)
{
	int	i;

	i = -1;
	while (rgb[++i])
	{
		str = ft_strtrim(rgb[i], " ");
		if (*str == '\0')
		{
			free_matrix(rgb);
			free(str);
			ft_exit(game, 2);
		}
		game->pars.floor[i] = ft_atoi(str);
		if (game->pars.floor[i] < 0 || game->pars.floor[i] > 255)
		{
			free_matrix(rgb);
			free(str);
			ft_exit(game, 2);
		}
		free(str);
	}
}

void	set_floor(t_game *game)
{
	char	*str;
	char	**rgb;
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
	set_floor2(game, rgb, str);
	free_matrix(rgb);
}
