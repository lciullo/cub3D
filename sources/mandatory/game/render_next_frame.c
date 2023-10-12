/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_next_frame.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lciullo <lciullo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 14:38:18 by cllovio           #+#    #+#             */
/*   Updated: 2023/10/12 17:31:31 by lciullo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	init_image(t_data *data, t_draw *draw);

#include <stdio.h>

int	can_mouse(t_data *data)
{
	if (data->left_mouse == 1)
	{
		data->angle += M_PI / 36;
		data->left_mouse = 0;
		mlx_mouse_move(data->mlx, data->win, SIZE_X / 2, SIZE_Y / 2);
		//mlx_mouse_hide(data->mlx, data->win);
	}
	else if (data->right_mouse == 1)
	{
		data->angle -= M_PI / 36;
		data->right_mouse = 0;
		mlx_mouse_move(data->mlx, data->win, SIZE_X / 2, SIZE_Y / 2);
		//mlx_mouse_hide(data->mlx, data->win);
	}
	return (0);
}

int	render_next_frame(t_data *data)
{
	t_draw	draw;

	if (init_image(data, &draw) == FAILURE)
		return (FAILURE);
	can_mouse(data);
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
