/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofadhel <ofadhel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 18:02:16 by ofadhel           #+#    #+#             */
/*   Updated: 2024/02/14 18:02:55 by ofadhel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	get_map_size(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->pars.file[i])
	{
		if (game->pars.file[i][0] == '1' || game->pars.file[i][0] == ' ')
			break;
		i++;
	}
	j = 0;
	while (game->pars.file[i])
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
	while (game->pars.file[i])
	{
		if (width < ft_strlen(game->pars.file[i]))
			width = ft_strlen(game->pars.file[i]);
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
	while (game->pars.file[i])
	{
		l = 0;
		game->map[k] = malloc(sizeof(char) * (width + 1));
		while (game->pars.file[i][l])
		{
			if (game->pars.file[i][l] == ' ')
				game->map[k][l] = '0';
			else
				game->map[k][l] = game->pars.file[i][l];
			l++;
		}
		while (l < width)
		{
			game->map[k][l] = '0';
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
	if (!game->pars.no || !game->pars.ea || !game->pars.so || !game->pars.we || !game->pars.c || !game->pars.f)
		ft_exit(game, 2);
	while (game->pars.file[i])
	{
		if (game->pars.file[i][0] == '1' || game->pars.file[i][0] == ' ')
			break;
		i++;
	}
	parse_map(game, i);
	//check now that is full closed. look zero and see if it has all around 1
}

/*void	xpm_img(t_game *game)
{
	game->north_texture = mlx_xpm_file_to_image(game->mlx, game->pars.no,
			1920, 1080);
	if (!game->north_texture)
		ft_exit(game, 2);
	game->south_texture = mlx_xpm_file_to_image(game->mlx, game->pars.so,
			1920, 1080);
	if (!game->south_texture)
		ft_exit(game, 2);
	game->east_texture = mlx_xpm_file_to_image(game->mlx, game->pars.ea,
			1920, 1080);
	if (!game->east_texture)
		ft_exit(game, 2);
	game->west_texture = mlx_xpm_file_to_image(game->mlx, game->pars.we,
			1920, 1080);
	if (!game->west_texture)
		ft_exit(game, 2);
}*/

void	parser(char **av, t_game *game)
{
	check_map_name(av[1]);
	read_file(av[1], game);
	check_file(game);
	print_matrix(game->map);
	//checkmap(game);
	set_rgb(game);
	//xpm_img(game);
}
