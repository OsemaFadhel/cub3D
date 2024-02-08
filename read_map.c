/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofadhel <ofadhel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 10:30:18 by ofadhel           #+#    #+#             */
/*   Updated: 2024/02/08 16:12:27 by ofadhel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/cub3d.h"

char	**read_file(char *file, t_game *game)
{
	int		fd;
	char	*line;
	char	**map;
	int		i = 0;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		ft_exit(game, 1);
	line = get_next_line(fd);
	printf("line: %s\n", line);
	close(fd);
	return (map);
}
