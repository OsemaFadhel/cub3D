/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofadhel <ofadhel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 16:20:41 by ofadhel           #+#    #+#             */
/*   Updated: 2024/03/29 22:17:53 by ofadhel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	read__file2(char *file, t_game *game, int i)
{
	int		fd;
	char	*line;
	int		j;

	game->pars.file = malloc(sizeof(char *) * (i + 1));
	fd = open(file, O_RDONLY);
	i = 0;
	line = get_next_line(fd);
	while (line)
	{
		if (line[0] != '\n')
		{
			game->pars.file[i] = ft_strdup(line);
			j = ft_strlen(game->pars.file[i]);
			game->pars.file[i][j - 1] = '\0';
			i++;
		}
		free(line);
		line = get_next_line(fd);
	}
	game->pars.file[i] = NULL;
	close(fd);
}

void	read_file(char *file, t_game *game)
{
	int		fd;
	char	*line;
	int		i;

	i = 0;
	fd = open(file, O_RDONLY);
	if (fd < 0)
		ft_exit(game, 1);
	line = get_next_line(fd);
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		i++;
	}
	close(fd);
	read__file2(file, game, i);
}

int	check_file(t_game *game)
{
	int	i;

	i = 0;
	check_textures(game);
	if (!game->pars.no || !game->pars.ea || !game->pars.so
		|| !game->pars.we || !game->pars.c || !game->pars.f)
		ft_exit(game, 2);
	while (game->pars.file[i])
	{
		if (game->pars.file[i][0] == '1' || game->pars.file[i][0] == ' ')
			break ;
		i++;
	}
	game->map.width = get_map_width(game, i);
	game->map.height = get_map_size(game);
	return (i);
}
