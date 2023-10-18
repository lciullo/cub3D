/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_game_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lciullo <lciullo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 14:20:24 by cllovio           #+#    #+#             */
/*   Updated: 2023/10/18 16:14:20 by lciullo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

static void	draw_wall(int *y, t_raycasting *raycasting, int y_max, \
			long size_wall);
static void	draw_ceilling_and_floor(int *y, t_raycasting *raycasting, \
			int y_max, int color);

void	draw_game(t_raycasting *raycasting, double distance, double angle, \
		int i)
{
	int		y;
	long	size_wall;
	long	half_size_wall;

	if (distance == 0)
		distance = 0.2;
	size_wall = 1 / (distance * cos(angle)) * 40000;
	half_size_wall = size_wall / 2;
	y = 0;
	raycasting->x = i;
	draw_ceilling_and_floor(&y, raycasting, ((SIZE_Y >> 1) - half_size_wall), \
	raycasting->data->celling);
	draw_wall(&y, raycasting, ((SIZE_Y >> 1) + half_size_wall), size_wall);
	draw_ceilling_and_floor(&y, raycasting, SIZE_Y, raycasting->data->floor);
}

float	float_modulo(float nbr, int div)
{
	int	i;

	i = nbr / div;
	nbr -= div * i;
	return (nbr);
}

static void	draw_wall(int *y, t_raycasting *raycasting, int y_max, \
long size_wall)
{
	int	color;
	/*int	x_pixel_get;
	int	y_pixel_get;*/

	color = 0;
	/*x_pixel_get = 0;
	y_pixel_get = 0;*/
	while (*y <= y_max)
	{
		if (raycasting->data->horizontal == true)
			color = get_pixel_ns(size_wall, y, raycasting);
		else if (raycasting->data->horizontal == false)
			color = get_pixel_we(size_wall, y, raycasting);
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
