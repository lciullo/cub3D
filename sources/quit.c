#include "cub3D.h"

#ifdef __linux__

int	quit_game(t_data *data)
{
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	exit(0);
	return (0);
}

#elif __APPLE__

int	quit_game(t_data *data)
{
	mlx_destroy_window(data->mlx, data->win);
	free(data->mlx);
	exit(0);
	return (0);
}

#endif
