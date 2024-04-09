/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_convert.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofadhel <ofadhel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 22:08:38 by ofadhel           #+#    #+#             */
/*   Updated: 2024/04/10 01:07:10 by ofadhel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	free_texture(t_game *game)
{
	free(game->pars.ea);
	free(game->pars.no);
	free(game->pars.so);
	free(game->pars.we);
	free(game->pars.f);
	free(game->pars.c);
}

void	ft_xpm(t_game *game)
{
	int	x;
	int	y;
	int	z;

	game->textures.stored[0] = mlx_get_data_addr(game->textures.wall_no,
			&x, &y, &z);
	if (!game->textures.stored[0])
		ft_exit(game, 5);
	game->textures.stored[1] = mlx_get_data_addr(game->textures.wall_so,
			&x, &y, &z);
	if (!game->textures.stored[1])
		ft_exit(game, 5);
	game->textures.stored[2] = mlx_get_data_addr(game->textures.wall_ea,
			&x, &y, &z);
	if (!game->textures.stored[2])
		ft_exit(game, 5);
	game->textures.stored[3] = mlx_get_data_addr(game->textures.wall_we,
			&x, &y, &z);
	if (!game->textures.stored[3])
		ft_exit(game, 5);
}

void	ft_mlx_xpm_file_to_image(t_mlx *mlx, t_game *game)
{
	game->textures.wall_ea = mlx_xpm_file_to_image(mlx->init, game->pars.ea,
			&game->textures.width, &game->textures.height);
	if (!game->textures.wall_ea)
		ft_exit(game, 5);
	game->textures.wall_no = mlx_xpm_file_to_image(mlx->init, game->pars.no,
			&game->textures.width, &game->textures.height);
	if (!game->textures.wall_no)
		ft_exit(game, 5);
	game->textures.wall_so = mlx_xpm_file_to_image(mlx->init, game->pars.so,
			&game->textures.width, &game->textures.height);
	if (!game->textures.wall_so)
		ft_exit(game, 5);
	game->textures.wall_we = mlx_xpm_file_to_image(mlx->init, game->pars.we,
			&game->textures.width, &game->textures.height);
	if (!game->textures.wall_we)
		ft_exit(game, 5);
	ft_xpm(game);
	free_texture(game);
}
