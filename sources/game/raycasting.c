/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cllovio <cllovio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 14:36:07 by cllovio           #+#    #+#             */
/*   Updated: 2023/10/16 17:25:35 by cllovio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static double	get_wall_distance(t_raycasting *raycasting);
static void		init_angle_struct_raycasting(t_raycasting *raycasting, t_data *data, double angle);
static bool		did_we_reach_a_wall(t_raycasting *raycasting, int x, int y);

#include "stdio.h"

void	raycasting(t_data *data, t_draw *draw)
{
	int				i;
	double			distance;
	t_raycasting	raycasting;
	double			adj;
	double			opp;
	double			angle;
	
	i = 1;
	adj = 0;
	opp = 0;
	init_struct_raycasting(&raycasting, data, draw);
	opp = SIZE_X / 2;
	adj = opp / tan(M_PI / 6);
	angle = (M_PI / 6) + data->angle;
	while (i <= SIZE_X)
	{
		init_angle_struct_raycasting(&raycasting, data, angle);
		distance = get_wall_distance(&raycasting);
		draw_game(&raycasting, distance, angle - data->angle, i);
		i++;
		opp--;
		angle = atanf(opp /adj) + data->angle;
	}
}

static void	init_angle_struct_raycasting(t_raycasting *raycasting, \
			t_data *data, double angle)
{
	data->collision_cor[0] = 0;
	data->collision_cor[1] = 0;
	raycasting->cos_angle = cosf(angle);
	raycasting->sin_angle = -sinf(angle);
}

static double	get_wall_distance(t_raycasting *raycasting)
{
	float	x;
	float	y;
	float	first_x;
	float	first_y;
	int		t_x;
	int		t_y;
	double		distance;

	t_x = 0;
	t_y = 0;
	x = raycasting->data->px_map + t_x * raycasting->cos_angle;
	y = raycasting->data->py_map + t_y * raycasting->sin_angle;
	distance = 0;
	first_x = x;
	first_y = y;
	while (1)
	{
		if (did_we_reach_a_wall(raycasting, (int)x, (int)y) == true)
		{
			raycasting->data->horizontal = true;
			raycasting->data->collision_cor[0] = x;
			raycasting->data->collision_cor[1] = y + 1;
			break ;
		}
		t_x += 1;
		x = raycasting->data->px_map + t_x * raycasting->cos_angle / 10;
		if (did_we_reach_a_wall(raycasting, (int)x, (int)y) == true)
		{
			raycasting->data->horizontal = false;
			raycasting->data->collision_cor[0] = x + 1;
			raycasting->data->collision_cor[1] = y;
			break ;
		}
		t_y += 1;
		y = raycasting->data->py_map + t_y * raycasting->sin_angle / 10;
	}
	distance = sqrt(powf((x - first_x), 2) + powf((y - first_y), 2));
	return (distance);
}

/*raycasting->data->map[(y + 1) / SQUARE_SIZE][x / SQUARE_SIZE] == '1' \
	|| raycasting->data->map[y / SQUARE_SIZE][(x + 1) / SQUARE_SIZE] == '1'*/
static bool	did_we_reach_a_wall(t_raycasting *raycasting, int x, int y)
{
	if (raycasting->data->map[(int)(y / SQUARE_SIZE)][(int)(x / SQUARE_SIZE)] == '1' || raycasting->data->map[(int)(y + 0.9) / SQUARE_SIZE][x / SQUARE_SIZE] == '1' \
	|| raycasting->data->map[y / SQUARE_SIZE][(int)(x + 0.9) / SQUARE_SIZE] == '1')
		return (true);
	return (false);
}
