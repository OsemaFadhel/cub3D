/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofadhel <ofadhel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 16:23:16 by ofadhel           #+#    #+#             */
/*   Updated: 2024/04/10 03:51:26 by ofadhel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"


int	skip_spaces(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == ' ')
			i++;
		else if (str[i] == '\t')
			i += 3;
		else
			break ;
	}
	return (i);
}

int	check_textures_4(t_game *game, int i, char *str, int *j)
{
	if (game->pars.file[i][0] == 'N' && game->pars.file[i][1] == 'O'
			&& game->pars.file[i][2] == ' ')
	{
		str = ft_strdup(ft_strchr(game->pars.file[i], ' '));
		str[ft_strlen(str) - 1] = '\0';
		if (!str)
			ft_exit(game, 2);
		game->pars.no = ft_strdup(str + skip_spaces(str));
		free(str);
		(*j)++;
	}
	else if (game->pars.file[i][0] == 'C' && game->pars.file[i][1] == ' ')
	{
		str = ft_strdup(ft_strchr(game->pars.file[i], ' '));
		str[ft_strlen(str) - 1] = '\0';
		if (!str)
			ft_exit(game, 2);
		game->pars.c = ft_strdup(str + skip_spaces(str));
		free(str);
		(*j)++;
	}
	else if (game->pars.file[i][0] == '1' || game->pars.file[i][0] == ' ')
		return (-1);
	return (0);
}

int	check_textures_3(t_game *game, int i, char *str)
{
	if (game->pars.file[i][0] == 'E' && game->pars.file[i][1] == 'A'
			&& game->pars.file[i][2] == ' ')
	{
		str = ft_strdup(ft_strchr(game->pars.file[i], ' '));
		str[ft_strlen(str) - 1] = '\0';
		if (!str)
			ft_exit(game, 2);
		game->pars.ea = ft_strdup(str + skip_spaces(str));
		free(str);
		return (0);
	}
	else if (game->pars.file[i][0] == 'F' && game->pars.file[i][1] == ' ')
	{
		str = ft_strdup(ft_strchr(game->pars.file[i], ' '));
		str[ft_strlen(str) - 1] = '\0';
		if (!str)
			ft_exit(game, 2);
		game->pars.f = ft_strdup(str + skip_spaces(str));
		free(str);
		return (0);
	}
	return (1);
}

int	check_textures_2(t_game *game, int i, char *str)
{
	if (game->pars.file[i][0] == 'S' && game->pars.file[i][1] == 'O'
			&& game->pars.file[i][2] == ' ')
	{
		str = ft_strdup(ft_strchr(game->pars.file[i], ' '));
		str[ft_strlen(str) - 1] = '\0';
		if (!str)
			ft_exit(game, 2);
		game->pars.so = ft_strdup(str + skip_spaces(str));
		free(str);
		return (0);
	}
	else if (game->pars.file[i][0] == 'W' && game->pars.file[i][1] == 'E'
			&& game->pars.file[i][2] == ' ')
	{
		str = ft_strdup(ft_strchr(game->pars.file[i], ' '));
		str[ft_strlen(str) - 1] = '\0';
		if (!str)
			ft_exit(game, 2);
		game->pars.we = ft_strdup(str + skip_spaces(str));
		free(str);
		return (0);
	}
	return (1);
}

void	check_textures(t_game *game)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	while (game->pars.file[i])
	{
		if (check_textures_2(game, i, str) == 0)
			j++;
		else if (check_textures_3(game, i, str) == 0)
			j++ ;
		else if (check_textures_4(game, i, str, &j) == -1)
			break ;
		i++;
	}
	if (j != 6)
		ft_exit(game, 2);
}
