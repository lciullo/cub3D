/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_next_frame.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cllovio <cllovio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 14:38:18 by cllovio           #+#    #+#             */
/*   Updated: 2023/10/14 13:34:00 by cllovio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	init_image(t_data *data, t_draw *draw);
static void	key_hook(t_data *data);

#include <stdio.h>
int	render_next_frame(t_data *data)
{
	t_draw	draw;

	if (init_image(data, &draw) == FAILURE)
		return (FAILURE);
	key_hook(data);
	raycasting(data, &draw);
	mini_map(data, &draw);
	mlx_put_image_to_window(data->mlx, data->win, draw.img, 0, 0);
	mlx_destroy_image(data->mlx, draw.img);
	mlx_do_sync(data->mlx);
	return (SUCCESS);
}

static int	init_image(t_data *data, t_draw *draw)
{
	draw->img = mlx_new_image(data->mlx, SIZE_X, SIZE_Y);
	if (draw->img == NULL)
		return (print_error_mlx(), quit_game(data), FAILURE);
	draw->addr = mlx_get_data_addr(draw->img, &draw->bits_per_pixel, \
	&draw->line_length, &draw->endian);
	if (draw->addr == NULL)
		return (print_error_mlx(), quit_game(data), FAILURE);
	return (SUCCESS);
}


static void	key_hook(t_data *data)
{
	if (data->key_hook.escape == 1)
	{
		quit_game(data);
		return ;	
	}
	if (data->key_hook.move_up == 1)
		move_up(data);
	if (data->key_hook.move_left == 1)
		move_left(data);
	if (data->key_hook.move_down == 1)
		move_down(data);
	if (data->key_hook.move_right == 1)
		move_right(data);
	if (data->key_hook.rotate_left == 1)
	{
		data->angle += M_PI / 36;
		// if (data->angle < 0)
		// 	data->angle = 2 * M_PI;
	}
	if (data->key_hook.rotate_right == 1)
	{
		data->angle -= M_PI / 36;
		// if (data->angle > 2 * M_PI)
		// 	data->angle = 0;
	}
}