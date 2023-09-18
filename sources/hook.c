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
	if (keycode == W_KEY || keycode == UP_KEY)
		move_up(game);
	if (keycode == A_KEY || keycode == LEFT_KEY)
			move_left(game);
	if (keycode == S_KEY || keycode == DOWN_KEY)
		move_down(game);
	if (keycode == D_KEY || keycode == RIGHT_KEY)
			move_right(game);
	return (SUCCESS);
}
