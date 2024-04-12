/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofadhel <ofadhel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 21:40:17 by ofadhel           #+#    #+#             */
/*   Updated: 2024/04/12 20:29:10 by ofadhel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/cub3d.h"

int	print_matrix(char **matrix)
{
	int	i;

	i = 0;
	while (matrix[i])
	{
		printf("%s", matrix[i]);
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

int	ft_exit(t_game *game, int i) //till 3 is parser errors, 4 is mlx errors, 5 is texture errors
{
	if (i < 4) //all parser errors
	{
		if (i == 1)
			printf("Error: map file not found\n");
		if (i == 2)
			printf("Error: map infos\n");
		if (i == 3)
			printf("Error: map not closed\n");
		if (game->pars.no)
			free(game->pars.no);
		if (game->pars.so)
			free(game->pars.so);
		if (game->pars.we)
			free(game->pars.we);
		if (game->pars.ea)
			free(game->pars.ea);
		if (game->pars.f)
			free(game->pars.f);
		if (game->pars.c)
			free(game->pars.c);
		if (game->map.map)
			free_matrix(game->map.map);
		exit(1);
	}
	if (i == 4) //image convert errors
		{
			printf("Error: textures\n");
			free(game->mlx.init);
			free_matrix(game->map.map);
			exit(1);
		}
	if (i == 5)
		printf("Error: raycasting\n");
	if (i == 6)
		printf("Error: mlx\n");
	free_matrix(game->map.map);
	mlx_destroy_window(game->mlx.init, game->mlx.win);
	mlx_destroy_image(game->mlx.init, game->mlx.img);
	mlx_destroy_image(game->mlx.init, game->textures.wall_no);
	mlx_destroy_image(game->mlx.init, game->textures.wall_so);
	mlx_destroy_image(game->mlx.init, game->textures.wall_ea);
	mlx_destroy_image(game->mlx.init, game->textures.wall_we);
	//free(game->mlx.address);
	exit(1);
}
