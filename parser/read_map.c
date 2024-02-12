/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_game.file.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofadhel <ofadhel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 10:30:18 by ofadhel           #+#    #+#             */
/*   Updated: 2024/02/08 16:35:52 by ofadhel          ###   ########.fr       */
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

void	parse_map(t_game *game, int i)
{
	int	j;
	int	k;

	j = 0;
	k = 0;
	j = get_map_size(game);
	check_closed(game, i);
	game->map = malloc(sizeof(char *) * (j + 1));
	//now parse map filling spaces with 1 and malloc all same size
	while (game->file[i])
	{
		game->map[k] = ft_strdup(game->file[i]);
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
	//print_matrix(game->map);
	//checkmap(game);
}
