/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cllovio <cllovio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 14:36:07 by cllovio           #+#    #+#             */
/*   Updated: 2023/10/17 13:18:35 by cllovio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	get_wall_distance(t_raycasting *raycasting);
static void	init_angle_struct_raycasting(t_raycasting *raycasting, \
			t_data *data);
static bool	check_col(char **map, t_pointf *xy, t_raycasting *raycasting, \
			int type);

void	raycasting(t_data *data, t_draw *draw)
{
	int				i;
	t_raycasting	raycasting;

	i = 1;
	init_struct_raycasting(&raycasting, data, draw);
	raycasting.opp = SIZE_X / 2;
	raycasting.adj = raycasting.opp / tan(M_PI / 6);
	raycasting.angle = (M_PI / 6) + data->angle;
	while (i <= SIZE_X)
	{
		init_angle_struct_raycasting(&raycasting, data);
		get_wall_distance(&raycasting);
		draw_game(&raycasting, raycasting.distance, \
		raycasting.angle - data->angle, i);
		i++;
		raycasting.opp--;
		raycasting.angle = atanf(raycasting.opp / raycasting.adj) + data->angle;
	}
}

static void	init_angle_struct_raycasting(t_raycasting *raycasting, t_data *data)
{
	data->collision_cor[0] = 0;
	data->collision_cor[1] = 0;
	raycasting->cos_angle = cosf(raycasting->angle);
	raycasting->sin_angle = -sinf(raycasting->angle);
}

static void	get_wall_distance(t_raycasting *raycasting)
{
	t_pointf	xy;
	t_point		t_xy;
	t_pointf	first_xy;

	t_xy.x = 0;
	t_xy.y = 0;
	xy.x = raycasting->data->px_map + t_xy.x * raycasting->cos_angle;
	xy.y = raycasting->data->py_map + t_xy.y * raycasting->sin_angle;
	raycasting->distance = 0;
	first_xy.x = xy.x;
	first_xy.y = xy.y;
	while (1)
	{
		if (check_col(raycasting->data->map, &xy, raycasting, 1) == true)
			break ;
		t_xy.x += 1;
		xy.x = raycasting->data->px_map + t_xy.x * raycasting->cos_angle / 10;
		if (check_col(raycasting->data->map, &xy, raycasting, 0) == true)
			break ;
		t_xy.y += 1;
		xy.y = raycasting->data->py_map + t_xy.y * raycasting->sin_angle / 10;
	}
	raycasting->distance = sqrt(powf((xy.x - first_xy.x), 2) + \
	powf((xy.y - first_xy.y), 2));
}

static bool	check_col(char **map, t_pointf *xy, t_raycasting *raycasting, \
			int type)
{
	if (type == 1 && \
	(map[(int)(xy->y / SQUARE_SIZE)][(int)(xy->x / SQUARE_SIZE)] == '1' \
	|| map[(int)(xy->y + 0.9) / SQUARE_SIZE][(int)xy->x / SQUARE_SIZE] == '1' \
	|| map[(int)xy->y / SQUARE_SIZE][(int)(xy->x + 0.9) / SQUARE_SIZE] == '1'))
	{
		raycasting->data->horizontal = true;
		raycasting->data->collision_cor[0] = xy->x;
		raycasting->data->collision_cor[1] = xy->y + 1;
		return (true);
	}
	else if (type == 0 && \
	(map[(int)(xy->y / SQUARE_SIZE)][(int)(xy->x / SQUARE_SIZE)] == '1' \
	|| map[(int)(xy->y + 0.9) / SQUARE_SIZE][(int)xy->x / SQUARE_SIZE] == '1' \
	|| map[(int)xy->y / SQUARE_SIZE][(int)(xy->x + 0.9) / SQUARE_SIZE] == '1'))
	{
		raycasting->data->horizontal = false;
		raycasting->data->collision_cor[0] = xy->x + 1;
		raycasting->data->collision_cor[1] = xy->y;
		return (true);
	}
	return (false);
}
