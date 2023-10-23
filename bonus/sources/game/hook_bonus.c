/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lciullo <lciullo@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 14:33:59 by cllovio           #+#    #+#             */
/*   Updated: 2023/10/19 16:03:25 by lciullo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

static int	key_press(int key_code, t_data *data);
static int	key_release(int key_code, t_data *data);
static int	mouse_key_hook(int x, int y, t_data *data);

void	hook(t_data *data)
{
	mlx_hook(data->win, ON_DESTROY, 0, quit_game, data);
	mlx_hook(data->win, 6, 1L << 6, mouse_key_hook, data);
	mlx_hook(data->win, 2, 1L << 0, key_press, data);
	mlx_hook(data->win, 3, 1L << 1, key_release, data);
	mlx_loop_hook(data->mlx, render_next_frame, data);
	mlx_loop(data->mlx);
}

static int	key_press(int key_code, t_data *data)
{
	if (key_code == ESC)
		data->key_hook.escape = 1;
	if (key_code == W_KEY)
		data->key_hook.move_up = 1;
	if (key_code == A_KEY)
		data->key_hook.move_left = 1;
	if (key_code == S_KEY)
		data->key_hook.move_down = 1;
	if (key_code == D_KEY)
		data->key_hook.move_right = 1;
	if (key_code == LEFT_KEY)
		data->key_hook.rotate_left = 1;
	if (key_code == RIGHT_KEY)
		data->key_hook.rotate_right = 1;
	if (key_code == M_KEY)
	{
		if (data->key_hook.mini_map == 0)
			data->key_hook.mini_map = 1;
		else if (data->key_hook.mini_map == 1)
			data->key_hook.mini_map = 0;
	}
	return (SUCCESS);
}

static int	key_release(int key_code, t_data *data)
{
	if (key_code == ESC)
		data->key_hook.escape = 0;
	if (key_code == W_KEY)
		data->key_hook.move_up = 0;
	if (key_code == A_KEY)
		data->key_hook.move_left = 0;
	if (key_code == S_KEY)
		data->key_hook.move_down = 0;
	if (key_code == D_KEY)
		data->key_hook.move_right = 0;
	if (key_code == LEFT_KEY)
		data->key_hook.rotate_left = 0;
	if (key_code == RIGHT_KEY)
		data->key_hook.rotate_right = 0;
	return (SUCCESS);
}

static int	mouse_key_hook(int x, int y, t_data *data)
{
	(void)y;
	if (x > HALF_WIDTH)
		data->key_hook.right_mouse = 1;
	else if (x < HALF_WIDTH)
		data->key_hook.left_mouse = 1;
	return (0);
}
