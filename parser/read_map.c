/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofadhel <ofadhel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 18:02:16 by ofadhel           #+#    #+#             */
/*   Updated: 2024/04/10 03:53:44 by ofadhel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	parse_map_while(t_game *game, int i)
{
	game->map.map[game->pars.k] = malloc(sizeof(char) * (game->map.width + 1));
	while (game->pars.file[i][game->pars.m])
	{
		if (game->pars.file[i][game->pars.m] == ' ')
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
		game->map.map[game->pars.k][game->pars.l - 1] = ' ';
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

void	check_characters(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while (game->map.map[++i])
	{
		j = -1;
		while (game->map.map[i][++j])
		{
			if (game->map.map[i][j] != '0' && game->map.map[i][j] != '1')
				ft_exit(game, 2);
		}
	}
}

void	fill_spaces(t_game *game)
{
	int	y;
	int	x;
	int	flag;

	y = 0;
	flag = 0;
	while (game->map.map[y])
	{
		x = -1;
		while (game->map.map[y][++x])
		{
			if (game->map.map[y][x] == ' ')
				game->map.map[y][x] = '1';
			if (game->map.map[y][x] == 'N' || game->map.map[y][x] == 'S'
				|| game->map.map[y][x] == 'W' || game->map.map[y][x] == 'E')
			{
				if (flag == 1)
					ft_exit(game, 2);
				game->map.map[y][x] = '0';
				flag = 1;
			}
		}
		y++;
	}
	check_characters(game);
}

void	parser(char **av, t_game *game)
{
	int	i;

	check_map_name(av[1]);
	read_file(av[1], game);
	i = check_file(game);
	parse_map(game, i);
	check_closed(game);
	fill_spaces(game);
	set_rgb(game);
	print_matrix(game->pars.file);
}
