#include "cub3D.h"

static void d_key(t_data *data);
static void	w_key(t_data *data);
static void a_key(t_data *data);
static void s_key(t_data *data);

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
		w_key(data);
	if (key_code == A_KEY)
		a_key(data);
	if (key_code == S_KEY)
		s_key(data);
	if (key_code == D_KEY)
		d_key(data);
	if (key_code == LEFT_KEY)
	{
		data->angle += (M_PI * 10) / 180;
		// rajouter securite voir se que j'ai pas push sur mon mac
		data->N = false;
		data->S = false;
		data->W = true;
		data->E = false;
	}
	if (key_code == RIGHT_KEY)
	{
		data->angle -= (M_PI * 10) / 180;
		// rajouter securite voir se que j'ai pas push sur mon mac
		data->N = false;
		data->S = false;
		data->W = false;
		data->E = true;
	}
	return (SUCCESS);
}

static void	w_key(t_data *data)
{
	if (data->N == true)
		move_up(data);
	else if (data->S == true)
		move_down(data);
	else if (data->E == true)
		move_right(data);
	else if (data->W == true)
		move_left(data);
}

static void a_key(t_data *data)
{
	if (data->N == true)
		move_left(data);
	else if (data->S == true)
		move_right(data);
	else if (data->W == true)
		move_down(data);
	else if (data->E == true)
		move_up(data);
}

static void s_key(t_data *data)
{
	if (data->N == true)
		move_down(data);
	else if (data->S == true)
		move_up(data);
	else if (data->W == true)
		move_right(data);
	else if (data->E == true)
		move_left(data);
}

static void d_key(t_data *data)
{
	if (data->N == true)
		move_right(data);
	else if (data->S == true)
		move_left(data);
	else if (data->W == true)
		move_up(data);
	else if (data->E == true)
		move_down(data);
}