/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofadhel <ofadhel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 21:40:17 by ofadhel           #+#    #+#             */
/*   Updated: 2024/03/29 18:27:31 by ofadhel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/cub3d.h"

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
		printf("Error: map textures\n");
	if (i == 3)
		printf("Error: map not closed\n");
	if (i == 4)
		printf("Error: raycasting\n");
		exit(1);
	//mlx_destroy_window(game->mlx, game->win);
	free_matrix(game->pars.file);
	free(game->map.map);
	exit(1);
}
