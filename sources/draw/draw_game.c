/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cllovio <cllovio@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 14:20:24 by cllovio           #+#    #+#             */
/*   Updated: 2023/10/10 17:43:19 by cllovio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	draw_wall(long *y, t_raycasting *raycasting, t_data *data, int y_max, int color);
static void	draw_ceilling_and_floor(long *y, t_raycasting *raycasting, \
			int y_max, int color);

void	draw_game(t_data *data, t_raycasting *raycasting, double distance)
{
	long	y;
	long	size_wall;
	long	half_size_wall;

	if (distance == 0)
		distance = 0.2;
	size_wall = (1 / (distance * cos(raycasting->shift))) * 40000;
	half_size_wall = size_wall / 2;
	y = 0;
	draw_ceilling_and_floor(&y, raycasting, ((SIZE_Y / 2) - half_size_wall), \
	raycasting->data->celling);
	draw_wall(&y, raycasting, data, ((SIZE_Y / 2) + half_size_wall), H_GREY);
	draw_ceilling_and_floor(&y, raycasting, SIZE_Y, raycasting->data->floor);
}

#include <stdio.h>

static void	draw_wall(long *y, t_raycasting *raycasting, t_data *data, int y_max, int color)
{
	(void)color;
	int color_1;
	// t_draw test;
	// int size = 100;
	(void)data;

	// init_texture(&test, "./textures/north.xpm", data->mlx);
	while (*y <= y_max)
	{
		color_1 = my_mlx_pixel_get(&raycasting->data->N_texture, ((raycasting->x % SQUARE_SIZE) * 100) / SQUARE_SIZE, ((*y % SQUARE_SIZE) * 100) / SQUARE_SIZE);
		my_mlx_pixel_put(raycasting->draw, raycasting->x, *y, color_1);
		(*y)++;
	}
	// mlx_destroy_image(data->mlx, test.img);
}

void	draw_ceilling_and_floor(long *y, t_raycasting *raycasting, int y_max, \
		int color)
{
	while (*y < y_max)
	{
		my_mlx_pixel_put(raycasting->draw, raycasting->x, *y, color);
		(*y)++;
	}
}
