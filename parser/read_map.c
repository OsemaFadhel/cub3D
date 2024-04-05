/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofadhel <ofadhel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 18:02:16 by ofadhel           #+#    #+#             */
/*   Updated: 2024/04/05 23:27:45 by ofadhel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	get_map_size(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->pars.file[i])
	{
		if (game->pars.file[i][0] == '1' || game->pars.file[i][0] == ' ')
			break ;
		i++;
	}
	j = 0;
	while (game->pars.file[i])
	{
		j++;
		i++;
	}
	return (j);
}

int	get_map_width(t_game *game, int i)
{
	int	j;
	int	k;
	int	width;

	j = 0;
	width = 0;
	while (game->pars.file[i])
	{
		k = 0;
		j = 0;
		while (game->pars.file[i][j])
		{
			if (game->pars.file[i][j] == ' ')
				k++;
			else if (game->pars.file[i][j] == '\t')
				k += 4;
			else
				k++;
			j++;
		}
		if (k > width)
			width = k;
		i++;
	}
	return (width);
}

void	parse_map_while(t_game *game, int i)
{
	game->map.map[game->pars.k] = malloc(sizeof(char) * (game->map.width + 1));
	while (game->pars.file[i][game->pars.m])
	{
		if (game->pars.file[i][game->pars.m] == ' '
			|| game->pars.file[i][game->pars.m] == '\n')
			game->map.map[game->pars.k][game->pars.l] = ' ';
		else if (game->pars.file[i][game->pars.m] == '\t')
		{
			game->map.map[game->pars.k][game->pars.l] = ' ';
			game->map.map[game->pars.k][game->pars.l + 1] = ' ';
			game->map.map[game->pars.k][game->pars.l + 2] = ' ';
			game->map.map[game->pars.k][game->pars.l + 3] = ' ';
			game->pars.l += 3;
		}
		else
			game->map.map[game->pars.k][game->pars.l]
				= game->pars.file[i][game->pars.m];
		game->pars.l++;
		game->pars.m++;
	}
}

void	parse_map(t_game *game, int i)
{
	game->map.map = malloc(sizeof(char *) * (game->map.height + 1));
	while (game->pars.file[i])
	{
		game->pars.l = 0;
		game->pars.m = 0;
		parse_map_while(game, i);
		while (game->pars.l < game->map.width)
		{
			game->map.map[game->pars.k][game->pars.l] = ' ';
			game->pars.l++;
		}
		game->map.map[game->pars.k][game->pars.l] = '\0';
		i++;
		game->pars.k++;
	}
	game->map.map[game->pars.k] = NULL;
}

void	fill_spaces(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (game->map.map[y])
	{
		x = 0;
		while (game->map.map[y][x])
		{
			if (game->map.map[y][x] == ' ')
				game->map.map[y][x] = '1';
			x++;
		}
		y++;
	}
}

void	parser(char **av, t_game *game) //xpm_img
{
	int	i;

	read_file(av[1], game);
	check_map_name(av[1]);
	i = check_file(game);
	parse_map(game, i);
	check_characters(game);
	check_closed(game);
	fill_spaces(game);
	set_rgb(game);
}
