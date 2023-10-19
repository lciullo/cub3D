/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_collision.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lciullo <lciullo@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 14:59:19 by cllovio           #+#    #+#             */
/*   Updated: 2023/10/19 16:04:47 by lciullo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

bool	check_collision_y(float map_y, float px_map, char **map)
{
	if (map[(int)(((map_y + HIT_BOX) / SQUARE_SIZE))][(int)((((px_map) / \
	SQUARE_SIZE)))] != '1' && map[(int)(((map_y - HIT_BOX) / \
	SQUARE_SIZE))][(int)((((px_map) / SQUARE_SIZE)))] != '1')
		return (true);
	return (false);
}

bool	check_collision_x(float map_x, float py_map, char **map)
{
	if (map[(int)(((py_map) / SQUARE_SIZE))][(int)((((map_x + HIT_BOX) / \
	SQUARE_SIZE)))] != '1' && map[(int)(((py_map) / \
	SQUARE_SIZE))][(int)((((map_x - HIT_BOX) / SQUARE_SIZE)))] != '1')
		return (true);
	return (false);
}
