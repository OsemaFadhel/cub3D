/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofadhel <ofadhel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 20:59:04 by ofadhel           #+#    #+#             */
/*   Updated: 2024/04/04 15:07:47 by ofadhel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/cub3d.h"

void	render(t_game *game)
{
	raycasting(game);
	//mlx_put_image_to_window(&game->mlx.init, game->mlx.win,
	//	game->mlx.img, 0, 0);
}

int	game_loop(t_game *game)
{
	render(game);
	return (0);
}

int	run_mlx(t_mlx *mlx, t_game *game)
{
	mlx_loop_hook(mlx->init, game_loop, game);
	mlx_hook(mlx->win, 17, 0, ft_exit, game);
	mlx_hook(mlx->win, 2, 0, ft_key_press, game);
	mlx_hook(mlx->win, 3, 1, ft_key_release, game);
	//mlx_put_image_to_window(mlx->init, mlx->win, mlx->img, 0, 0);
	mlx_loop(mlx->init);
	return (1);
}

int	init_mlx(t_mlx *mlx, t_game *game)
{
	mlx->init = mlx_init();
	if (!mlx->init)
		ft_exit(game, 4);
	mlx->win = mlx_new_window(mlx->init, 1366, 768, "cub3d");
	if (!mlx->win)
		ft_exit(game, 4);
	mlx->img = mlx_new_image(mlx->init, 1366, 768);
	if (!mlx->img)
		ft_exit(game, 4);
	mlx->address = mlx_get_data_addr(mlx->img, &mlx->bits_per_pixel,
			&mlx->size_line, &mlx->endian);
	if (!mlx->address)
		ft_exit(game, 4);
	ft_mlx_xpm_file_to_image(mlx, game);
	run_mlx(mlx, game);
	return (0);
}

void	init_struct(char **av)
{
	t_game	game;

	init(&game);
	printf("Parsing the map OSEMA\n");
	parser(av, &game);
	printf("Initializing the game DANIEL\n");
	init_camera_position(&game.player, &game.map, &game.camera);
	printf("Initializing mlx DANIEL\n");
	init_mlx(&game.mlx, &game);
}

int	main(int ac, char **av)
{
	t_game	game;

	if (ac != 2)
	{
		printf("Error: no map or too many arguments\n");
		return (1);
	}
	init_struct(av);
	return (0);
}
