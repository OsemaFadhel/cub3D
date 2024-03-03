/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofadhel <ofadhel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 20:59:04 by ofadhel           #+#    #+#             */
/*   Updated: 2024/03/03 23:07:29 by ofadhel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/cub3d.h"

int	run_mlx(t_mlx *mlx, t_game *game)
{
	mlx_loop_hook(mlx->init, game_loop, game); //raycasting.c
	mlx_put_image_to_window(mlx->init, mlx->win, mlx->img, 0, 0);
	//mlx_hook(game->mlx.win, 17, 0, ft_exit, &game);
	mlx_key_hook(game->mlx.win, ft_key, &game);
	mlx_loop(mlx->init);
	return (1);
}

int	init_mlx(t_mlx *mlx, t_game *game)
{
	mlx->init = mlx_init();
	if (!mlx->init)
		ft_exit(game, 4);
	mlx->win = mlx_new_window(mlx->init, 1920, 1080, "cub3d");
	if (!mlx->win)
		ft_exit(game, 4);
	mlx->img = mlx_new_image(mlx->init, 1920, 1080);
	if (!mlx->img)
		ft_exit(game, 4);
	mlx->address = mlx_get_data_addr(mlx->img, &mlx->bits_per_pixel,
			&mlx->line_length, &mlx->endian);
	if (!mlx->address)
		ft_exit(game, 4);
	//to_xpm(mlx, game); // parser/image_convert.c
						//in parse there is already one, well se later when we create the textures
	run_mlx(mlx, game); //raycasting.c
	return (0);
}

void	init_struct(char **av)
{
	t_game	game;
	init(&game); //init.c
	parser(av, &game); //parser osema
	init_camera_position(&game.player, &game.map, &game.camera); //init_pos.c
	init_mlx(&game.mlx, &game); //main.c
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
