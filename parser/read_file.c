/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofadhel <ofadhel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 16:20:41 by ofadhel           #+#    #+#             */
/*   Updated: 2024/04/14 20:04:37 by ofadhel          ###   ########.fr       */
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
		ft_printf("Error: map file be .cub\n");
		exit(1);
	}
}

int	read__file2(char *file, t_game *game, int i)
{
	int		fd;
	char	*line;
	int		status;
	int		flag;

	flag = 0;
	status = 0;
	game->pars.file = ft_calloc(sizeof(char *), (i + 1));
	fd = open(file, O_RDONLY);
	i = 0;
	line = get_next_line(fd);
	while (line)
	{
		if (line[0] == '1' || line[0] == ' ')
			flag = 1;
		game->pars.file[i] = ft_strdup(line);
		if (flag == 1 && game->pars.file[i][0] == '\n')
			status = -1;
		i++;
		free(line);
		line = get_next_line(fd);
	}
	game->pars.file[i] = NULL;
	return (free(line), close(fd), status);
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
	free(line);
	if (read__file2(file, game, i) == -1)
		ft_exit(game, 1);
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
		{
			if (game->pars.file[i - 1][0] == '\0'
				|| game->pars.file[i - 1][0] == '\n')
				break ;
			ft_exit(game, 1);
		}
		i++;
	}
	if (!game->pars.file[i])
		ft_exit(game, 1);
	game->map.width = get_map_width(game, i);
	game->map.height = get_map_size(game);
	return (i);
}
