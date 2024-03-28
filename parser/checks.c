/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofadhel <ofadhel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 16:23:16 by ofadhel           #+#    #+#             */
/*   Updated: 2024/03/28 16:10:28 by ofadhel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	check_map_name(char *str)
{
	int	i;

	i = ft_strlen(str);
	if (str[i - 1] != 'b' || str[i - 2] != 'u' || str[i - 3] != 'c'
		|| str[i - 4] != '.')
	{
		ft_printf("Error: map name must be .game\n");
		exit(1);
	}
}

void	check_textures(t_game *game)
{
	int	i;
	char *str;

	i = 0;
	while (game->pars.file[i])
	{
		if (game->pars.file[i][0] == 'N' && game->pars.file[i][1] == 'O' && game->pars.file[i][2] == ' ')
		{
			str = ft_strchr(game->pars.file[i], ' ');
			if (!str)
				ft_exit(game, 2);
			game->pars.no = ft_strdup(str + 1);
		}
		else if (game->pars.file[i][0] == 'S' && game->pars.file[i][1] == 'O' && game->pars.file[i][2] == ' ')
		{
			str = ft_strchr(game->pars.file[i], ' ');
			if (!str)
				ft_exit(game, 2);
			game->pars.so = ft_strdup(str + 1);
		}
		else if (game->pars.file[i][0] == 'W' && game->pars.file[i][1] == 'E' && game->pars.file[i][2] == ' ')
		{
			str = ft_strchr(game->pars.file[i], ' ');
			if (!str)
				ft_exit(game, 2);
			game->pars.we = ft_strdup(str + 1);
		}
		else if (game->pars.file[i][0] == 'E' && game->pars.file[i][1] == 'A' && game->pars.file[i][2] == ' ')
		{
			str = ft_strchr(game->pars.file[i], ' ');
			if (!str)
				ft_exit(game, 2);
			game->pars.ea = ft_strdup(str + 1);
		}
		else if (game->pars.file[i][0] == 'F' && game->pars.file[i][1] == ' ')
		{
			str = ft_strchr(game->pars.file[i], ' ');
			if (!str)
				ft_exit(game, 2);
			game->pars.f = ft_strdup(str + 1);
		}
		else if (game->pars.file[i][0] == 'C' && game->pars.file[i][1] == ' ')
		{
			str = ft_strchr(game->pars.file[i], ' ');
			if (!str)
				ft_exit(game, 2);
			game->pars.c = ft_strdup(str + 1);
		}
		else if (game->pars.file[i][0] == '1' || game->pars.file[i][0] == ' ')
			break ;
		i++;
	}
	if (i != 6)
		ft_exit(game, 2);
}


void	check_characters(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map.map[i])
	{
		j = 0;
		while (game->map.map[i][j])
		{
			if (game->map.map[i][j] != '0' && game->map.map[i][j] != '1' && game->map.map[i][j] != 'N'
				&& game->map.map[i][j] != 'S' && game->map.map[i][j] != 'E'
					&& game->map.map[i][j] != 'W' && game->map.map[i][j] != ' ')
				ft_exit(game, 3);
			j++;
		}
		i++;
	}
}

/*
void flood_fill(t_game *game, char **map, int x, int y)
{
	int	width;
	int size;

	size = get_map_size(game);
	width = game->map.width;

	if (x < 0 || y < 0 || x >= width || y >= size)
		ft_exit(game, 3);
	if (map[y][x] != '0' && map[y][x] != ' ' && map[y][x] != 'G' && map[y][x] != 'W' && map[y][x] != 'E'
			&& map[y][x] != 'S' && map[y][x] != 'N')
		return ;
    map[y][x] = 'X';
    flood_fill(game, map, x + 1, y);
    flood_fill(game, map, x - 1, y);
    flood_fill(game, map, x, y + 1);
    flood_fill(game, map, x, y - 1);
/*	flood_fill(game, map, x + 1, y + 1);
	flood_fill(game, map, x - 1, y - 1);
	flood_fill(game, map, x + 1, y - 1);
	flood_fill(game, map, x - 1, y + 1);*/
//}

void	check_closed(t_game *game)
{
	int player_x;
	int player_y;
	int i;
	int	j;
	char **map;

	i = -1;
	while (++i < game->map.height)
	{
		j = -1;
        while (++j < game->map.width)
		{
			if (game->map.map[i][j] == 'S' || game->map.map[i][j] == 'N' || game->map.map[i][j] == 'E' || game->map.map[i][j] == 'W')
			{
				game->map.player_x = i;
				game->map.player_y = j;
				game->map.player_orientation = game->map.map[i][j];
				break;
			}
		}
	}
	printf("map width = %d\n", game->map.width);
	printf("map height = %d\n", game->map.height);
	printf("check_closed_top\n");
	check_closed_top(game);
	printf("check_closed_bottom\n");
	check_closed_bottom(game, game->map.height - 1);
	printf("check_closed_edges\n");
	check_closed_edges(game);
	/*map = malloc(sizeof(char *) * (size + 1));
	while (game->map.map[++i])
		map[i] = ft_strdup(game->map.map[i]);
	map[i] = NULL;
    flood_fill(game, map, game->map.player_x, game->map.player_y);
	free_matrix(map);*/
}
