/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pixel_textures_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lciullo <lciullo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 14:33:38 by cllovio           #+#    #+#             */
/*   Updated: 2023/10/18 16:14:29 by lciullo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

int	get_pixel_ns(long size_wall, int *y, t_raycasting *raycasting)
{
	int	x_pixel_get;
	int	y_pixel_get;
	int	color;

	color = 0;
	x_pixel_get = ((float_modulo(raycasting->data->collision_cor[0], \
	SQUARE_SIZE) * IMG_SIZE) / SQUARE_SIZE);
	y_pixel_get = (((*y - ((SIZE_Y >> 1) - (size_wall >> 1))) * IMG_SIZE) \
	/ (size_wall));
	if (raycasting->sin_angle < 0)
		color = my_mlx_pixel_get(&raycasting->data->N_texture, x_pixel_get, \
		y_pixel_get);
	else if (raycasting->sin_angle > 0)
	{
		x_pixel_get = (IMG_SIZE - 1) - x_pixel_get;
		color = my_mlx_pixel_get(&raycasting->data->S_texture, x_pixel_get, \
		y_pixel_get);
	}
	return (color);
}

int	get_pixel_we(long size_wall, int *y, t_raycasting *raycasting)
{
	int	x_pixel_get;
	int	y_pixel_get;
	int	color;

	color = 0;
	x_pixel_get = ((float_modulo(raycasting->data->collision_cor[1], \
	SQUARE_SIZE) * IMG_SIZE) / SQUARE_SIZE);
	y_pixel_get = (((*y - ((SIZE_Y >> 1) - (size_wall >> 1))) * IMG_SIZE) \
	/ (size_wall));
	if (raycasting->cos_angle < 0)
	{
		x_pixel_get = (IMG_SIZE - 1) - x_pixel_get;
		color = my_mlx_pixel_get(&raycasting->data->W_texture, x_pixel_get, \
		y_pixel_get);
	}
	else if (raycasting->cos_angle > 0)
		color = my_mlx_pixel_get(&raycasting->data->E_texture, x_pixel_get, \
		y_pixel_get);
	return (color);
}
