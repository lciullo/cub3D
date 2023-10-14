/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cllovio <cllovio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 14:33:59 by cllovio           #+#    #+#             */
/*   Updated: 2023/10/14 13:37:14 by cllovio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	key_press(int key_code, t_data *data);
static int	key_release(int key_code, t_data *data);

void	hook(t_data *data)
{
	mlx_hook(data->win, ON_DESTROY, 0, quit_game, data);
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
