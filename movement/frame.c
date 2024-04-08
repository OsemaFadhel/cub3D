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


void  get_frame_time(t_game *game)
{
    char    *fps;
    game->old_time = game->time;
    game->time = get_time();
    game->frame_time = (game->time - game->old_time) / 1000.0;
    game->frame_per_second = (1 / game->frame_time);

    if (game->frame_per_second > 60)
	{
		ft_sleep(((1.0 / 60) - game->frame_time) * 1000);
		game->time = get_time();
		game->frame_time = (game->time - game->old_time) / 1000.0;
		game->frame_per_second = (1 / game->frame_time);
	}
    //double c = game->frame_time * 3.0;

    fps = ft_itoa(game->frame_per_second);
	free(fps);
}










