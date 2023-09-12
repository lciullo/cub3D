#include "cub3D.h"

void	hook(t_data *data)
{
	mlx_hook(data->win, ON_KEYDOWN, 27, key_hook, data);
	mlx_hook(data->win, ON_DESTROY, 0, quit_game, data);
}

int	key_hook(int key_code, t_data *data)
{
	if (key_code == ESC)
		return (quit_game(data), SUCCESS);
	return (SUCCESS);
}
