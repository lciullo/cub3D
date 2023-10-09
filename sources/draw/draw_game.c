/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cllovio <cllovio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 14:20:24 by cllovio           #+#    #+#             */
/*   Updated: 2023/10/09 17:36:49 by cllovio          ###   ########.fr       */
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
	// int y_bis;
	// y_bis = *y;
	//(void)color;
	while (*y <= y_max)
	{
		// printf("%d %ld\n", raycasting->x, *y);
		color = my_mlx_pixel_get(data->N_texture->img, ((raycasting->x % SQUARE_SIZE) * 100) / SQUARE_SIZE, ((*y % SQUARE_SIZE) * 100) / SQUARE_SIZE);
		printf("%d", color);
		//my_mlx_pixel_put(raycasting->draw, raycasting->x, *y, color);
		*y = *y +1;
	}
}

void	draw_ceilling_and_floor(long *y, t_raycasting *raycasting, int y_max, \
		int color)
{
	while (*y < y_max)
	{
		my_mlx_pixel_put(raycasting->draw, raycasting->x, *y, color);
		*y = *y + 1;
	}
}
