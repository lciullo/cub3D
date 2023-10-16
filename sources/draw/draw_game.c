/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cllovio <cllovio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 14:20:24 by cllovio           #+#    #+#             */
/*   Updated: 2023/10/16 16:27:02 by cllovio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	draw_wall(int *y, t_raycasting *raycasting, int y_max, long size_wall, int i);
static void	draw_ceilling_and_floor(int *y, t_raycasting *raycasting, \
			int y_max, int color, int i);

void	draw_game(t_raycasting *raycasting, double distance, double angle, int i)
{
	int	y;
	long	size_wall;
	long	half_size_wall;

	(void)angle;
	if (distance == 0)
		distance = 0.2;
	size_wall = 1 / (distance * cos(angle)) * 40000;
	half_size_wall = size_wall / 2;
	y = 0;
	draw_ceilling_and_floor(&y, raycasting, ((SIZE_Y / 2) - half_size_wall), \
	raycasting->data->celling, i);
	draw_wall(&y, raycasting, ((SIZE_Y / 2) + half_size_wall), size_wall, i);
	draw_ceilling_and_floor(&y, raycasting, SIZE_Y, raycasting->data->floor, i);
}

float	float_modulo(float nbr, int div)
{
	int	i;
	
	i = nbr / div;
	nbr -= div * i;
	return (nbr);	
}

static void	draw_wall(int *y, t_raycasting *raycasting, int y_max, long size_wall, int i)
{
	int color;
	int	x_pixel_get;
	int	y_pixel_get;
	
	x_pixel_get = 0;
	y_pixel_get = 0;
	while (*y <= y_max)
	{
		if (raycasting->data->horizontal == true)
		{
			x_pixel_get = ((float_modulo(raycasting->data->collision_cor[0], SQUARE_SIZE) * IMG_SIZE) / SQUARE_SIZE);
			y_pixel_get = (((*y - ((SIZE_Y >> 1) - (size_wall >> 1))) * IMG_SIZE) / (size_wall));
			if (raycasting->sin_angle < 0)
			{
				color = my_mlx_pixel_get(&raycasting->data->N_texture, x_pixel_get, y_pixel_get);
			}
			else if (raycasting->sin_angle > 0)
			{
				x_pixel_get = (IMG_SIZE - 1) - x_pixel_get;
				color = my_mlx_pixel_get(&raycasting->data->S_texture, x_pixel_get, y_pixel_get);
			}
		}
		else if (raycasting->data->horizontal == false)
		{
			x_pixel_get = ((float_modulo(raycasting->data->collision_cor[1], SQUARE_SIZE) * IMG_SIZE) / SQUARE_SIZE);
			y_pixel_get = (((*y - ((SIZE_Y >> 1) - (size_wall >> 1))) * IMG_SIZE) / (size_wall));
			if (raycasting->cos_angle < 0)
			{
				x_pixel_get= (IMG_SIZE - 1) - x_pixel_get;
				color = my_mlx_pixel_get(&raycasting->data->W_texture, x_pixel_get, y_pixel_get);
			}
			else if (raycasting->cos_angle > 0)
				color = my_mlx_pixel_get(&raycasting->data->E_texture, x_pixel_get, y_pixel_get);
		}
		my_mlx_pixel_put(raycasting->draw, i, *y, color);
		(*y)++;
	}
}

void	draw_ceilling_and_floor(int *y, t_raycasting *raycasting, int y_max, \
		int color, int i)
{
	while (*y < y_max)
	{
		my_mlx_pixel_put(raycasting->draw, i, *y, color);
		(*y)++;
	}
}
