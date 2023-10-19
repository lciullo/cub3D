/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pixel_textures.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cllovio <cllovio@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 14:33:38 by cllovio           #+#    #+#             */
/*   Updated: 2023/10/19 12:59:23 by cllovio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static float	float_modulo(float nbr, int div);

int	get_pixel_ns(long size_wall, int *y, t_raycasting *raycasting)
{
	int	x_pixel_get;
	int	y_pixel_get;
	int	color;

	color = 0;
	x_pixel_get = ((float_modulo(raycasting->data->collision_cor[0], \
	SQUARE_SIZE) * IMG_SIZE) / SQUARE_SIZE);
	y_pixel_get = (((*y - ((HALF_HEIGHT) - (size_wall >> 1))) * IMG_SIZE) \
	/ (size_wall));
	if (raycasting->sin_angle < 0)
		color = my_mlx_pixel_get(&raycasting->data->n_texture, x_pixel_get, \
		y_pixel_get);
	else if (raycasting->sin_angle > 0)
	{
		x_pixel_get = (IMG_SIZE - 1) - x_pixel_get;
		color = my_mlx_pixel_get(&raycasting->data->s_texture, x_pixel_get, \
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
	y_pixel_get = (((*y - ((HALF_HEIGHT) - (size_wall >> 1))) * IMG_SIZE) \
	/ (size_wall));
	if (raycasting->cos_angle < 0)
	{
		x_pixel_get = (IMG_SIZE - 1) - x_pixel_get;
		color = my_mlx_pixel_get(&raycasting->data->w_texture, x_pixel_get, \
		y_pixel_get);
	}
	else if (raycasting->cos_angle > 0)
		color = my_mlx_pixel_get(&raycasting->data->e_texture, x_pixel_get, \
		y_pixel_get);
	return (color);
}

static float	float_modulo(float nbr, int div)
{
	int	i;

	i = nbr / div;
	nbr -= div * i;
	return (nbr);
}
