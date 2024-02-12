/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofadhel <ofadhel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 16:20:41 by ofadhel           #+#    #+#             */
/*   Updated: 2024/02/12 16:20:50 by ofadhel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	read__file2(char *file, t_game *game, int i)
{
	int		fd;
	char	*line;
	int		j;

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

void	read_file(char *file, t_game *game)
{
	int		fd;
	char	*line;
	int		i;

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
	read__file2(file, game, i);
}
