/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofadhel <ofadhel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 16:23:16 by ofadhel           #+#    #+#             */
/*   Updated: 2024/03/03 21:26:27 by ofadhel          ###   ########.fr       */
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
	char *str;

	i = 0;
	while (game->pars.file[i])
	{
		if (game->pars.file[i][0] == 'N' && game->pars.file[i][1] == 'O' && game->pars.file[i][2] == ' ')
		{
			str = ft_strchr(game->pars.file[i], ' ');
			if (!str)
				ft_exit(game, 2);
			game->pars.no = ft_strdup(str + 1);
		}
		else if (game->pars.file[i][0] == 'S' && game->pars.file[i][1] == 'O' && game->pars.file[i][2] == ' ')
		{
			str = ft_strchr(game->pars.file[i], ' ');
			if (!str)
				ft_exit(game, 2);
			game->pars.so = ft_strdup(str + 1);
		}
		else if (game->pars.file[i][0] == 'W' && game->pars.file[i][1] == 'E' && game->pars.file[i][2] == ' ')
		{
			str = ft_strchr(game->pars.file[i], ' ');
			if (!str)
				ft_exit(game, 2);
			game->pars.we = ft_strdup(str + 1);
		}
		else if (game->pars.file[i][0] == 'E' && game->pars.file[i][1] == 'A' && game->pars.file[i][2] == ' ')
		{
			str = ft_strchr(game->pars.file[i], ' ');
			if (!str)
				ft_exit(game, 2);
			game->pars.ea = ft_strdup(str + 1);
		}
		else if (game->pars.file[i][0] == 'F' && game->pars.file[i][1] == ' ')
		{
			str = ft_strchr(game->pars.file[i], ' ');
			if (!str)
				ft_exit(game, 2);
			game->pars.f = ft_strdup(str + 1);
		}
		else if (game->pars.file[i][0] == 'C' && game->pars.file[i][1] == ' ')
		{
			str = ft_strchr(game->pars.file[i], ' ');
			if (!str)
				ft_exit(game, 2);
			game->pars.c = ft_strdup(str + 1);
		}
		else if (game->pars.file[i][0] == '1' || game->pars.file[i][0] == ' ')
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
	while (game->map.map[i - 1][j])
	{
		if (game->map.map[i - 1][j] == '1' || game->map.map[i - 1][j] == ' ')
			;
		else
			ft_exit(game, 3);
		j++;
	}
	while (game->map.map[l])
	{
		k = ft_strlen(game->map.map[l]) - 1;
		if (game->map.map[l][0] == '1' || game->map.map[l][0] == ' ')
			;
		else
			ft_exit(game, 3);
		if (game->map.map[l][k] == '1' || game->map.map[l][k] == ' ')
			;
		else
			ft_exit(game, 3);
		l++;
	}
}

void	check_closed(t_game *game)
{
	int	j;
	int	l;
	int	i;

	i = 0;
	l = 0;
	j = 0;
	while (game->map.map[i][j])
	{
		if (game->map.map[i][j] == '1' || game->map.map[i][j] == ' ')
			;
		else
		{
			ft_exit(game, 3);
		}
		j++;
	}
	j = 0;
	while (game->map.map[i])
		i++;
	check_closed2(game, i, l);
}
