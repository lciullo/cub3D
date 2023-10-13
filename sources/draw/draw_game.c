/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cllovio <cllovio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 14:20:24 by cllovio           #+#    #+#             */
/*   Updated: 2023/10/13 15:28:04 by cllovio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	draw_wall(int *y, t_raycasting *raycasting, int y_max, long size_wall);
static void	draw_ceilling_and_floor(int *y, t_raycasting *raycasting, \
			int y_max, int color);

void	draw_game(t_raycasting *raycasting, double distance)
{
	int	y;
	long	size_wall;
	long	half_size_wall;

	if (distance == 0)
		distance = 0.2;
	size_wall = (1 / (distance * cos(raycasting->shift))) * 40000;
	half_size_wall = size_wall / 2;
	y = 0;
	draw_ceilling_and_floor(&y, raycasting, ((SIZE_Y / 2) - half_size_wall), \
	raycasting->data->celling);
	draw_wall(&y, raycasting, ((SIZE_Y / 2) + half_size_wall), size_wall);
	draw_ceilling_and_floor(&y, raycasting, SIZE_Y, raycasting->data->floor);
}

#include <stdio.h>

static void	draw_wall(int *y, t_raycasting *raycasting, int y_max, long size_wall)
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
			x_pixel_get = (int)((((int)raycasting->data->collision_cor[1] % SQUARE_SIZE) * 100) / SQUARE_SIZE);
			y_pixel_get = (int)(((*y - ((SIZE_Y >> 1) - (size_wall >> 1))) * 100) / (size_wall));
			color = my_mlx_pixel_get(&raycasting->data->N_texture, x_pixel_get, y_pixel_get);
		}
		else if (raycasting->data->horizontal == false)
		{
			x_pixel_get = ((((int)raycasting->data->collision_cor[0] % SQUARE_SIZE) * 100) / SQUARE_SIZE);
			y_pixel_get = (int)(((*y - ((SIZE_Y >> 1) - (size_wall >> 1))) * 100) / (size_wall));			
			color = my_mlx_pixel_get(&raycasting->data->N_texture, x_pixel_get, y_pixel_get);
		}
		my_mlx_pixel_put(raycasting->draw, raycasting->x, *y, color);
		(*y)++;
	}
}

void	draw_ceilling_and_floor(int *y, t_raycasting *raycasting, int y_max, \
		int color)
{
	while (*y < y_max)
	{
		my_mlx_pixel_put(raycasting->draw, raycasting->x, *y, color);
		(*y)++;
	}
}
