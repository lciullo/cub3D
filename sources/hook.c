#include "cub3D.h"


void	hook(t_data *data)
{
	mlx_hook(data->win, ON_KEYDOWN, 27, key_hook, data);
	mlx_hook(data->win, ON_DESTROY, 0, quit_game, data);
	mlx_loop_hook(data->mlx, render_next_frame, data);
	mlx_loop(data->mlx);
}

int	key_hook(int key_code, t_data *data)
{
	if (key_code == ESC)
		return (quit_game(data), SUCCESS);
	if (key_code == W_KEY)
		move_up(data);
	if (key_code == A_KEY)
		move_left(data);
	if (key_code == S_KEY)
		move_down(data);
	if (key_code == D_KEY)
		move_right(data);
	if (key_code == LEFT_KEY)
	{
		data->angle +=  M_PI / 36;
		if (data->angle > 2 * M_PI)
			data->angle = 0;
	}
	if (key_code == RIGHT_KEY)
	{
		data->angle -= M_PI /36;
		if (data->angle < 0)
			data->angle = 2 * M_PI;
	}
	return (SUCCESS);
}
