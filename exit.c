/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofadhel <ofadhel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 21:40:17 by ofadhel           #+#    #+#             */
/*   Updated: 2024/04/10 02:46:09 by ofadhel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/cub3d.h"

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
		printf("Error: map not found\n");
		exit(1);
	}
	if (i == 2)
	{
		printf("Error: map textures\n");
		exit(1);
	}
	if (i == 3)
		printf("Error: map not closed\n");
	if (i == 4)
		printf("Error: raycasting\n");
	if (i == 5)
		printf("Error: texture file\n");
	free_matrix(game->pars.file);
	free_matrix(game->map.map);
	mlx_destroy_image(game->mlx.init, game->mlx.img);
	mlx_destroy_window(game->mlx.init, game->mlx.win);
	mlx_destroy_image(game->mlx.init, game->textures.wall_no);
	mlx_destroy_image(game->mlx.init, game->textures.wall_so);
	mlx_destroy_image(game->mlx.init, game->textures.wall_ea);
	mlx_destroy_image(game->mlx.init, game->textures.wall_we);
	mlx_destroy_display(game->mlx.init);
	free(game->mlx.init);
	free(game->mlx.address);
	free_matrix(game->textures.stored);
	free(game->map_axis);
	exit(1);
}
