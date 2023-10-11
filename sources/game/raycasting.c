/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cllovio <cllovio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 14:36:07 by cllovio           #+#    #+#             */
/*   Updated: 2023/10/09 16:54:01 by cllovio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static double	get_wall_distance(t_raycasting *raycasting);
static void		init_angle_struct_raycasting(int i, t_raycasting *raycasting, \
				t_data *data);
static bool		did_we_reach_a_wall(t_raycasting *raycasting, int x, int y);

void	raycasting(t_data *data, t_draw *draw)
{
	int				i;
	double			distance;
	t_raycasting	raycasting;

	i = 1;
	init_struct_raycasting(&raycasting, data, draw);
	while (i <= SIZE_X)
	{
		init_angle_struct_raycasting(i, &raycasting, data);
		distance = get_wall_distance(&raycasting);
		draw_game(data, &raycasting, distance);
		i++;
		raycasting.x--;
	}
}

static void	init_angle_struct_raycasting(int i, t_raycasting *raycasting, \
			t_data *data)
{
	raycasting->shift = ((float)i / SIZE_X) + 1;
	raycasting->cos_angle = cosf(raycasting->shift * (M_PI / 3) + data->angle);
	raycasting->sin_angle = -sinf(raycasting->shift * (M_PI / 3) + data->angle);
	raycasting->shift = (raycasting->shift - 1.5) * (M_PI / 3);
}

static double	get_wall_distance(t_raycasting *raycasting)
{
	int			x;
	int			y;
	float		t;
	double		distance;

	t = 0;
	x = raycasting->data->px_map + t * raycasting->cos_angle;
	y = raycasting->data->py_map + t * raycasting->sin_angle;
	distance = 0;
	while (1)
	{
		if (did_we_reach_a_wall(raycasting, x, y) == true)
			break ;
		t += 1;
		x = raycasting->data->px_map + t * raycasting->cos_angle / 10;
		y = raycasting->data->py_map + t * raycasting->sin_angle / 10;
		distance += 0.1;
	}
	return (distance);
}

static bool	did_we_reach_a_wall(t_raycasting *raycasting, int x, int y)
{
	if (raycasting->data->map[y / SQUARE_SIZE][x / SQUARE_SIZE] == '1' || \
	raycasting->data->map[(y + 1) / SQUARE_SIZE][x / SQUARE_SIZE] == '1' \
	|| raycasting->data->map[y / SQUARE_SIZE][(x + 1) / SQUARE_SIZE] == '1')
		return (true);
	return (false);
}
