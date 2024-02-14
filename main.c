/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofadhel <ofadhel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 20:59:04 by ofadhel           #+#    #+#             */
/*   Updated: 2024/02/14 17:06:13 by ofadhel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/cub3d.h"

void	init_parser(t_game *game)
{
	game->pars.no = NULL;
	game->pars.so = NULL;
	game->pars.ea = NULL;
	game->pars.we = NULL;
	game->pars.f = NULL;
	game->pars.c = NULL;
}

void	init(t_game *game)
{
	init_parser(game);
	game->floor_texture = 0;
	game->ceil_texture = 0;
	game->north_texture = 0;
	game->south_texture = 0;
	game->east_texture = 0;
	game->west_texture = 0;
}

void	free_matrix(char **matrix)
{
	int	i;

	i = -1;
	while (matrix[++i])
		free(matrix[i]);
	free(matrix);
}

int	ft_exit(t_game *game, int i)
{
	if (i == 1)
	{
		ft_printf("Error: map not found\n");
		exit(1);
	}
	if (i == 2)
	{
		printf("Error: map textures\n");
		free_matrix(game->pars.file);
		exit(1);
	}
	if (i == 3)
	{
		printf("Error: map not closed\n");
		free_matrix(game->pars.file);
		exit(1);
	}
	mlx_destroy_window(game->mlx, game->win);
	exit(1);
}

int	print_matrix(char **matrix)
{
	int	i;

	i = 0;
	while (matrix[i])
	{
		printf("%s\n", matrix[i]);
		i++;
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_game	game;

	if (ac != 2)
	{
		printf("Error: no map or too many arguments\n");
		return (1);
	}
	init(&game);
	parser(av, &game);
	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx, 1920, 1080, "Cub3D");
	//xpm_img(&game);
	//set_win(&game);
	mlx_key_hook(game.win, key, &game);
	mlx_hook(game.win, 17, 0, ft_exit, &game);
	mlx_loop(game.mlx);
	free(game.mlx);
	return (0);
}
