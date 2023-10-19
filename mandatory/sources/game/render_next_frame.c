/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_next_frame.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cllovio <cllovio@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 14:38:18 by cllovio           #+#    #+#             */
/*   Updated: 2023/10/19 15:17:10 by cllovio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	init_image(t_data *data, t_draw *draw);
static void	key_hook(t_data *data, t_draw *draw);

int	render_next_frame(t_data *data)
{
	t_draw	draw;

	if (init_image(data, &draw) == FAILURE)
		return (FAILURE);
	key_hook(data, &draw);
	raycasting(data, &draw, 1);
	mlx_put_image_to_window(data->mlx, data->win, draw.img, 0, 0);
	mlx_destroy_image(data->mlx, draw.img);
	mlx_do_sync(data->mlx);
	return (SUCCESS);
}

static int	init_image(t_data *data, t_draw *draw)
{
	draw->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	if (draw->img == NULL)
		return (print_error_mlx(), quit_game(data), FAILURE);
	draw->addr = mlx_get_data_addr(draw->img, &draw->bits_per_pixel, \
	&draw->line_length, &draw->endian);
	if (draw->addr == NULL)
	{
		mlx_destroy_image(data->mlx, draw->img);
		return (print_error_mlx(), quit_game(data), FAILURE);
	}
	return (SUCCESS);
}

static void	key_hook(t_data *data, t_draw *draw)
{
	if (data->key_hook.escape == 1)
	{
		mlx_destroy_image(data->mlx, draw->img);
		quit_game(data);
		return ;
	}
	if (data->key_hook.move_up == 1)
		move_front(data);
	if (data->key_hook.move_left == 1)
		move_left(data);
	if (data->key_hook.move_down == 1)
		move_back(data);
	if (data->key_hook.move_right == 1)
		move_right(data);
	if (data->key_hook.rotate_left == 1)
		data->angle += M_PI / 64;
	if (data->key_hook.rotate_right == 1)
		data->angle -= M_PI / 64;
}
