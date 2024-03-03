/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_convert.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofadhel <ofadhel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 22:08:38 by ofadhel           #+#    #+#             */
/*   Updated: 2024/03/03 22:35:50 by ofadhel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static void	check_size(int *width, int *height) // to change
{
	if (*width != 64)
		exit(1);
	if (*height != 64)
		exit(1);
}

static void	to_xpm_suite(t_game *game)
{
	int	x;
	int	y;
	int	z;

	game->textures.stored[0] = mlx_get_data_addr(game->textures.wall_no,
			&x, &y, &z);
	if (!game->textures.stored[0])
		ft_exit(game, 4);
	game->textures.stored[1] = mlx_get_data_addr(game->textures.wall_so,
			&x, &y, &z);
	if (!game->textures.stored[1])
		ft_exit(game, 4);
	game->textures.stored[2] = mlx_get_data_addr(game->textures.wall_ea,
			&x, &y, &z);
	if (!game->textures.stored[2])
		ft_exit(game, 4);
	game->textures.stored[3] = mlx_get_data_addr(game->textures.wall_we,
			&x, &y, &z);
	if (!game->textures.stored[3])
		ft_exit(game, 4);
}

void	to_xpm(t_mlx *mlx, t_game *game)
{
	game->textures.wall_ea = mlx_xpm_file_to_image(mlx->init, game->pars.ea,
			&game->textures.width, &game->textures.height);
	check_size(&game->textures.width, &game->textures.height);
	game->textures.wall_no = mlx_xpm_file_to_image(mlx->init, game->pars.no,
			&game->textures.width, &game->textures.height);
	check_size(&game->textures.width, &game->textures.height);
	game->textures.wall_so = mlx_xpm_file_to_image(mlx->init, game->pars.so,
			&game->textures.width, &game->textures.height);
	check_size(&game->textures.width, &game->textures.height);
	game->textures.wall_we = mlx_xpm_file_to_image(mlx->init, game->pars.we,
			&game->textures.width, &game->textures.height);
	check_size(&game->textures.width, &game->textures.height);
	to_xpm_suite(game);
}
