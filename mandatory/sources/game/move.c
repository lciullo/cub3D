/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lciullo <lciullo@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 14:31:34 by cllovio           #+#    #+#             */
/*   Updated: 2023/10/19 16:05:30 by lciullo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	move_front(t_data *data)
{
	float	added_value_y;
	float	added_value_x;
	float	map_y;
	float	map_x;

	added_value_y = GAP * sin(data->angle);
	added_value_x = GAP * cos(data->angle);
	map_y = data->py_map - added_value_y;
	map_x = data->px_map + added_value_x;
	if (check_collision_y(map_y, data->px_map, data->map) == true)
		data->py_map -= added_value_y;
	if (check_collision_x(map_x, data->py_map, data->map) == true)
		data->px_map += added_value_x;
}

void	move_back(t_data *data)
{
	float	added_value_y;
	float	added_value_x;
	float	map_y;
	float	map_x;

	added_value_y = GAP * sin(data->angle);
	added_value_x = GAP * cos(data->angle);
	map_y = data->py_map + added_value_y;
	map_x = data->px_map - added_value_x;
	if (check_collision_y(map_y, data->px_map, data->map) == true)
		data->py_map += added_value_y;
	if (check_collision_x(map_x, data->py_map, data->map) == true)
		data->px_map -= added_value_x;
}

void	move_left(t_data *data)
{
	float	added_value_y;
	float	added_value_x;
	float	map_y;
	float	map_x;

	added_value_y = GAP * sin(data->angle - M_PI_2);
	added_value_x = GAP * cos(data->angle + M_PI_2);
	map_y = data->py_map + added_value_y;
	map_x = data->px_map + added_value_x;
	if (check_collision_y(map_y, data->px_map, data->map) == true)
		data->py_map += added_value_y;
	if (check_collision_x(map_x, data->py_map, data->map) == true)
		data->px_map += added_value_x;
}

void	move_right(t_data *data)
{
	float	added_value_y;
	float	added_value_x;
	float	map_y;
	float	map_x;

	added_value_y = GAP * sin(data->angle + M_PI_2);
	added_value_x = GAP * cos(data->angle - M_PI_2);
	map_y = data->py_map + added_value_y;
	map_x = data->px_map + added_value_x;
	if (check_collision_y(map_y, data->px_map, data->map) == true)
		data->py_map += added_value_y;
	if (check_collision_x(map_x, data->py_map, data->map) == true)
		data->px_map += added_value_x;
}
