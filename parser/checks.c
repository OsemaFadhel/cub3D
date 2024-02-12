/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofadhel <ofadhel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 16:23:16 by ofadhel           #+#    #+#             */
/*   Updated: 2024/02/12 18:00:13 by ofadhel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

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

void	check_textures(t_game *game)
{
	int	i;

	i = 0;
	while (game->file[i])
	{
		if (game->file[i][0] == 'N' && game->file[i][1] == 'O')
			game->no = ft_strdup(ft_strchr(game->file[i], ' ') + 1);
		else if (game->file[i][0] == 'S' && game->file[i][1] == 'O')
			game->so = ft_strdup(ft_strchr(game->file[i], ' ') + 1);
		else if (game->file[i][0] == 'W' && game->file[i][1] == 'E')
			game->we = ft_strdup(ft_strchr(game->file[i], ' ') + 1);
		else if (game->file[i][0] == 'E' && game->file[i][1] == 'A')
			game->ea = ft_strdup(ft_strchr(game->file[i], ' ') + 1);
		else if (game->file[i][0] == 'F')
			game->f = ft_strdup(ft_strchr(game->file[i], ' ') + 1);
		else if (game->file[i][0] == 'C')
			game->c = ft_strdup(ft_strchr(game->file[i], ' ') + 1);
		else if (game->file[i][0] == '1' || game->file[i][0] == ' ')
			break ;
		i++;
	}
	if (i != 6)
		ft_exit(game, 2);
}

void	check_closed2(t_game *game, int i, int l)
{
	int	j;
	int	k;

	j = 0;
	while (game->file[i - 1][j])
	{
		if (game->file[i - 1][j] == '1' || game->file[i - 1][j] == ' ')
			;
		else
			ft_exit(game, 3);
		j++;
	}
	while (game->file[l])
	{
		k = ft_strlen(game->file[l]) - 1;
		if (game->file[l][0] == '1' || game->file[l][0] == ' ')
			;
		if (game->file[l][k] == '1' || game->file[l][k] == ' ')
			;
		else
			ft_exit(game, 3);
		l++;
	}
}

void	check_closed(t_game *game, int i)
{
	int	j;
	int	l;

	l = i;
	j = 0;
	while (game->file[i][j])
	{
		if (game->file[i][j] == '1' || game->file[i][j] == ' ')
			;
		else
			ft_exit(game, 3);
		j++;
	}
	j = 0;
	while (game->file[i])
		i++;
	check_closed2(game, i, l);
}
