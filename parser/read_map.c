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
		if (line[0] != '\n')
		{
			game->file[i] = ft_strdup(line);
			j = ft_strlen(game->file[i]);
			game->file[i][j - 1] = '\0';
			i++;
		}
		free(line);
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

void	check_textures(t_game *game)
{
	int	i;

	i = 0;
	while (game->file[i])
	{
		if (game->file[i][0] == 'N' && game->file[i][1] == 'O')
			game->no = ft_strdup(ft_strchr(game->file[i], ' ') + 1);
		else if (game->file[i][0] == 'S' && game->file[i][1] == 'O')
			game->so = ft_strdup(ft_strchr(game->file[i], ' ') + 1);
		else if (game->file[i][0] == 'W' && game->file[i][1] == 'E')
			game->we = ft_strdup(ft_strchr(game->file[i], ' ') + 1);
		else if (game->file[i][0] == 'E' && game->file[i][1] == 'A')
			game->ea = ft_strdup(ft_strchr(game->file[i], ' ') + 1);
		else if (game->file[i][0] == 'F')
			game->f = ft_strdup(ft_strchr(game->file[i], ' ') + 1);
		else if (game->file[i][0] == 'C')
			game->c = ft_strdup(ft_strchr(game->file[i], ' ') + 1);
		else if (game->file[i][0] == '1' || game->file[i][0] == ' ')
			break;
		i++;
	}
	if (i != 6)
		ft_exit(game, 2);
}

void check_closed(t_game *game, int i)
{
	int	j;
	int	l;
	int	k;

	l = i;
	j = 0;
	while (game->file[i][j])
	{
		if (game->file[i][j] == '1' || game->file[i][j] == ' ')
			;
		else
			ft_exit(game, 2);
		j++;
	}
	j = 0;
	while (game->file[i])
		i++;
	while (game->file[i - 1][j])
	{
		if (game->file[i - 1][j] == '1' || game->file[i - 1][j] == ' ')
		;
		else
			ft_exit(game, 2);
		j++;
	}
	while (game->file[l])
	{
		k = ft_strlen(game->file[l]) - 1;
		if (game->file[l][0] == '1' || game->file[l][0] == ' ')
			;
		if (game->file[l][k] == '1' || game->file[l][k] == ' ')
			;
		else
			ft_exit(game, 2);
		l++;
	}
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
	while (game->file[i])
	{
		if (!game->no || !game->ea || !game->so || !game->we || !game->c || !game->f)
			ft_exit(game, 2);
		else if (game->file[i][0] == '1' || game->file[i][0] == ' ')
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
