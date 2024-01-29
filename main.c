/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofadhel <ofadhel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 20:59:04 by ofadhel           #+#    #+#             */
/*   Updated: 2024/01/29 15:05:58 by ofadhel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/cub3d.h"

void	check_map_name(char *str)
{
	int	i;

	i = ft_strlen(str);
	if (str[i - 1] != 'b' || str[i - 2] != 'u' || str[i - 3] != 'c'
		|| str[i - 4] != '.')
	{
		ft_printf("Error: map name must be .cub\n");
		exit(1);
	}
}

/*int	close_game(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	free_map(game);
	exit(1);
}*/

int	main(int ac, char **av)
{
	t_game	game;

	if (ac != 2)
	{
		ft_printf("Error: no map or too many arguments\n");
		return (1);
	}
	check_map_name(av[1]);
	//game.map = read_map(av[1], &game);
	//init(&game);
	game.mlx = mlx_init();
	//map_size(&game);
	//checks(&game);
	game.win = mlx_new_window(game.mlx, 20,
			20, "cub3D");
	//xpm_img(&game);
	//set_win(&game);
	mlx_key_hook(game.win, key, &game);
	//mlx_hook(game.win, 17, 0, close_game, &game);
	mlx_loop(game.mlx);
	free(game.mlx);
	return (0);
}
