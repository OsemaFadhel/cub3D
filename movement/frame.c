/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frame.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofadhel <ofadhel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 14:20:04 by ofadhel           #+#    #+#             */
/*   Updated: 2024/04/11 19:07:25 by ofadhel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

u_int64_t	get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * (u_int64_t)1000) + (tv.tv_usec / 1000));
}

void	ft_sleep(u_int64_t time)
{
	u_int64_t	start;

	start = 0;
	start = get_time();
	while ((get_time() - start) < time)
		usleep(time / 10);
}


void	get_frame_time(t_game *game)
{
	game->frame.old_time = game->frame.time;
	game->frame.time = get_time();
	game->frame.frame_time = (game->frame.time - game->frame.old_time) / 1000.0;
	game->frame.frame_per_second = (int)(1.0 / game->frame.frame_time);
	if (game->frame.frame_per_second > 80)
	{
		ft_sleep(((1.0 / 80) - game->frame.frame_time) * 1000);
		game->frame.time = get_time();
		game->frame.frame_time = (game->frame.time - game->frame.old_time) / 1000.0;
		game->frame.frame_per_second = (int)(1.0 / game->frame.frame_time);
	}
	game->frame.fps = ft_itoa(game->frame.frame_per_second);
	game->player.move_speed = game->frame.frame_time * 5.0;
	game->player.rot_speed = game->frame.frame_time * 3.0;
}
