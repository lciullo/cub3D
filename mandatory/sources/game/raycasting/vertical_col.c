/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vertical_col.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cllovio <cllovio@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 15:47:21 by cllovio           #+#    #+#             */
/*   Updated: 2023/10/19 12:43:26 by cllovio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static double	vertical_col_pos(t_raycasting *raycasting, t_pointf *xy);
static bool		check_wall_vertical_pos(t_data *data, t_pointf *xy);
static double	vertical_col_neg(t_raycasting *raycasting, t_pointf *xy);
static bool		check_wall_vertical_neg(t_data *data, t_pointf *xy);

double	vertical_col(t_raycasting *raycasting, t_pointf *xy)
{
	double	distance;

	distance = 0;
	if (raycasting->cos_angle >= 0)
		distance = vertical_col_pos(raycasting, xy);
	else if (raycasting->cos_angle < 0)
		distance = vertical_col_neg(raycasting, xy);
	return (distance);
}

static double	vertical_col_pos(t_raycasting *raycasting, t_pointf *xy)
{
	float		depth_y;
	float		delta_depth;

	xy->y = 0;
	xy->x = 0;
	depth_y = 0;
	while (xy->x <= raycasting->data->px_map)
		xy->x += SQUARE_SIZE;
	depth_y = (xy->x - raycasting->data->px_map) / raycasting->cos_angle;
	xy->y = raycasting->data->py_map + depth_y * raycasting->sin_angle;
	delta_depth = (SQUARE_SIZE / raycasting->cos_angle) * raycasting->sin_angle;
	while (check_wall_vertical_pos(raycasting->data, xy) == true)
	{
		xy->y += delta_depth;
		xy->x += SQUARE_SIZE;
	}
	return (sqrt(powf((raycasting->data->px_map - xy->x), 2) + \
	powf((raycasting->data->py_map - xy->y), 2)));
}

static bool	check_wall_vertical_pos(t_data *data, t_pointf *xy)
{
	if (xy->x / SQUARE_SIZE > 0 && (xy->y / SQUARE_SIZE) > 0 && \
	(xy->y / SQUARE_SIZE) < data->size_map && \
	(xy->x / SQUARE_SIZE) < data->len_line[(int)(xy->y / SQUARE_SIZE)] && \
	(data->map[(int)(xy->y / SQUARE_SIZE)][(int)(xy->x / SQUARE_SIZE)] != '1'))
		return (true);
	return (false);
}

static double	vertical_col_neg(t_raycasting *raycasting, t_pointf *xy)
{
	float		depth_y;
	float		delta_depth;

	xy->y = 0;
	xy->x = 0;
	depth_y = 0;
	while (xy->x <= raycasting->data->px_map)
		xy->x += SQUARE_SIZE;
	xy->x -= SQUARE_SIZE;
	depth_y = (xy->x - raycasting->data->px_map) / \
	raycasting->cos_angle + 0.000000001;
	xy->y = raycasting->data->py_map + depth_y * raycasting->sin_angle;
	delta_depth = (SQUARE_SIZE / -raycasting->cos_angle) \
	* raycasting->sin_angle;
	while (check_wall_vertical_neg(raycasting->data, xy) == true)
	{
		xy->y += delta_depth;
		xy->x -= SQUARE_SIZE;
	}
	return (sqrt(powf((raycasting->data->px_map - xy->x), 2) + \
	powf((raycasting->data->py_map - xy->y), 2)));
}

static bool	check_wall_vertical_neg(t_data *data, t_pointf *xy)
{
	if ((xy->x - 0.000000001) / SQUARE_SIZE > 0 && \
	((xy->y - 0.000000001) / SQUARE_SIZE) > 0 && \
	((xy->y - 0.000000001) / SQUARE_SIZE) < data->size_map && \
	((xy->x - 0.000000001) / SQUARE_SIZE) < \
	data->len_line[(int)((xy->y - 0.000000001) / SQUARE_SIZE)] && \
	(data->map[(int)((xy->y - 0.000000001) / \
	SQUARE_SIZE)][(int)((xy->x - 0.000000001) / SQUARE_SIZE)] != '1'))
		return (true);
	return (false);
}
