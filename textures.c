/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofadhel <ofadhel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 22:37:43 by ofadhel           #+#    #+#             */
/*   Updated: 2024/02/23 22:54:35 by ofadhel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/cub3d.h"

void	init_textures(t_game *game)
{
	game->north_texture = mlx_xpm_file_to_image(game->mlx, game->pars.no, 64, 64);
	game->south_texture = mlx_xpm_file_to_image(game->mlx, game->pars.so, 64, 64);
	game->east_texture = mlx_xpm_file_to_image(game->mlx, game->pars.ea, 64, 64);
	game->west_texture = mlx_xpm_file_to_image(game->mlx, game->pars.we, 64, 64);
}
