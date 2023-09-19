#include "cub3D.h"

void	hook(t_data *data)
{
	mlx_hook(data->win, ON_KEYDOWN, 27, key_hook, data);
	mlx_hook(data->win, ON_DESTROY, 0, quit_game, data);
	mlx_loop_hook(data->mlx, render_next_frame, data);
}

int	key_hook(int key_code, t_data *data)
{
	if (key_code == ESC)
		return (quit_game(data), SUCCESS);
	if (key_code == W_KEY || key_code == UP_KEY)
		move_up(data);
	if (key_code == A_KEY || key_code == LEFT_KEY)
		move_left(data);
	if (key_code == S_KEY || key_code == DOWN_KEY)
		move_down(data);
	if (key_code == D_KEY || key_code == RIGHT_KEY)
		move_right(data);
	return (SUCCESS);
}
