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

void	read_file(char *file, t_game *game)
{
	int		fd;
	char	*line;
	char	**map;
	int		i;
	int		j;

	i = 0;
	fd = open(file, O_RDONLY);
	if (fd < 0)
		ft_exit(game, 1);
	while ((line = get_next_line(fd)))
	{
		free(line);
		i++;
	}
	close(fd);
	game->file = malloc(sizeof(char *) * (i + 1));
	fd = open(file, O_RDONLY);
	i = 0;
	while ((line = get_next_line(fd)))
	{
		game->file[i] = ft_strdup(line);
		free(line);
		j = ft_strlen(game->file[i]);
		game->file[i][j - 1] = '\0';
		i++;
	}
	game->file[i] = NULL;
	close(fd);
}

void	get_color(t_game *game, char *line, int i)
{
}

void	get_texture(t_game *game, char *line, int i)
{
}

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

void	check_file(t_game *game)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	k = 0;
	while (game->file[i])
	{
		if (game->file[i][0] == 'N' && game->file[i][1] == 'O')
			get_texture(game, game->file[i], 0);
		else if (game->file[i][0] == 'S' && game->file[i][1] == 'O')
			get_texture(game, game->file[i], 1);
		else if (game->file[i][0] == 'W' && game->file[i][1] == 'E')
			get_texture(game, game->file[i], 2);
		else if (game->file[i][0] == 'E' && game->file[i][1] == 'A')
			get_texture(game, game->file[i], 3);
		else if (game->file[i][0] == 'S' && game->file[i][1] == ' ')
			get_texture(game, game->file[i], 4);
		else if (game->file[i][0] == 'F')
			get_color(game, game->file[i], 0);
		else if (game->file[i][0] == 'C')
			get_color(game, game->file[i], 1);
		else if (game->file[i][0] == '1' || game->file[i][0] == ' ')
			break;
		i++;
	}
	j = get_map_size(game);
	game->map = malloc(sizeof(char *) * (j + 1));
	while (game->file[i])
	{
		game->map[k] = ft_strdup(game->file[i]);
		i++;
		k++;
	}
	game->map[k] = NULL;

}

void	parser(char **av, t_game *game)
{
	check_map_name(av[1]);
	read_file(av[1], game);
	check_file(game);
	//checkmap(game);
}
