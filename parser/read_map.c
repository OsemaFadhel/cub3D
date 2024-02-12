/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofadhel <ofadhel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 18:02:16 by ofadhel           #+#    #+#             */
/*   Updated: 2024/02/12 18:48:04 by ofadhel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	get_map_size(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->file[i])
	{
		if (game->file[i][0] == '1' || game->file[i][0] == ' ')
			break;
		i++;
	}
	j = 0;
	while (game->file[i])
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
	k = 0;
	width = 0;
	while (game->file[i])
	{
		if (width < ft_strlen(game->file[i]))
			width = ft_strlen(game->file[i]);
		i++;
	}
	return (width);
}

void	parse_map(t_game *game, int i)
{
	int	j;
	int	l;
	int	k;
	int	width;

	j = 0;
	k = 0;
	width = get_map_width(game, i);
	j = get_map_size(game);
	check_closed(game, i);

	game->map = malloc(sizeof(char *) * (j + 1));
	while (game->file[i])
	{
		l = 0;
		game->map[k] = malloc(sizeof(char) * (width + 1));
		while (game->file[i][l])
		{
			if (game->file[i][l] == ' ')
				game->map[k][l] = '1';
			else
				game->map[k][l] = game->file[i][l];
			l++;
		}
		while (l < width)
		{
			game->map[k][l] = '1';
			l++;
		}
		game->map[k][l] = '\0';
		i++;
		k++;
	}
	game->map[k] = NULL;
}

void	check_file(t_game *game)
{
	int	i;

	i = 0;
	check_textures(game);
	if (!game->no || !game->ea || !game->so || !game->we || !game->c || !game->f)
		ft_exit(game, 2);
	while (game->file[i])
	{
		if (game->file[i][0] == '1' || game->file[i][0] == ' ')
			break;
		i++;
	}
	parse_map(game, i);
}

void	parser(char **av, t_game *game)
{
	check_map_name(av[1]);
	read_file(av[1], game);
	check_file(game);
	print_matrix(game->map);
	//checkmap(game);
}
