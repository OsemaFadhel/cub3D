/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofadhel <ofadhel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 20:59:04 by ofadhel           #+#    #+#             */
/*   Updated: 2024/02/12 17:54:47 by ofadhel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/cub3d.h"

void	init(t_game *game)
{
	game->moves = 0;
	game->no = NULL;
	game->so = NULL;
	game->ea = NULL;
	game->we = NULL;
	game->f = NULL;
	game->c = NULL;
	game->player_x = 0;
	game->player_y = 0;
	game->coin_count = 0;
	game->start = 0;
	game->coin = 0;
	game->floor = 0;
	game->exit = 0;
	game->player = 0;
	game->map_width = 0;
	game->map_height = 0;
	game->enemy_move = 0;
}

void	free_matrix(char **matrix)
{
	int	i;

	i = -1;
	while (matrix[++i])
		free(matrix[i]);
	free(matrix);
}

void	ft_exit(t_game *game, int i)
{
	if (i == 1)
	{
		ft_printf("Error: map not found\n");
		exit(1);
	}
	if (i == 2)
	{
		printf("Error: map textures\n");
		free_matrix(game->file);
		exit(1);
	}
	if (i == 3)
	{
		printf("Error: map not closed\n");
		free_matrix(game->file);
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
