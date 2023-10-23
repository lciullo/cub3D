/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lciullo <lciullo@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 14:36:07 by cllovio           #+#    #+#             */
/*   Updated: 2023/10/19 15:28:20 by lciullo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

static void	init_angle_struct_raycasting(t_raycasting *raycasting, \
			t_data *data, t_pointf *xy_vert, t_pointf *xy_hori);
static void	draw_horizontal_collision(t_raycasting *raycasting, t_pointf *xy, \
			double distance, int i);
static void	draw_vertical_collision(t_raycasting *raycasting, \
			t_pointf *xy, double distance, int i);

void	raycasting(t_data *data, t_draw *draw, int i)
{
	t_raycasting	raycasting;
	double			dist_hori;
	double			dist_vert;
	t_pointf		xy_vert;
	t_pointf		xy_hori;

	init_struct_raycasting(&raycasting, data, draw);
	while (i <= WIDTH)
	{
		init_angle_struct_raycasting(&raycasting, data, &xy_vert, &xy_hori);
		dist_hori = horizontal_col(&raycasting, &xy_hori);
		dist_vert = vertical_col(&raycasting, &xy_vert);
		if (dist_hori <= dist_vert)
			draw_horizontal_collision(&raycasting, &xy_hori, dist_hori, i);
		else if (dist_hori > dist_vert)
			draw_vertical_collision(&raycasting, &xy_vert, dist_vert, i);
		i++;
		raycasting.opp--;
		raycasting.angle = atanf(raycasting.opp / raycasting.adj) + data->angle;
	}
}

static void	init_angle_struct_raycasting(t_raycasting *raycasting, \
			t_data *data, t_pointf *xy_vert, t_pointf *xy_hori)
{
	data->collision_cor[0] = 0;
	data->collision_cor[1] = 0;
	xy_vert->x = 0;
	xy_vert->y = 0;
	xy_hori->x = 0;
	xy_hori->y = 0;
	raycasting->cos_angle = cosf(raycasting->angle);
	raycasting->sin_angle = -sinf(raycasting->angle);
}

static void	draw_horizontal_collision(t_raycasting *raycasting, t_pointf *xy, \
			double distance, int i)
{
	raycasting->data->collision_cor[0] = xy->x;
	raycasting->data->collision_cor[1] = xy->y + 1;
	raycasting->data->horizontal = true;
	draw_game(raycasting, distance, \
	raycasting->angle - raycasting->data->angle, i);
}

static void	draw_vertical_collision(t_raycasting *raycasting, \
			t_pointf *xy, double distance, int i)
{
	raycasting->data->collision_cor[0] = xy->x + 1;
	raycasting->data->collision_cor[1] = xy->y;
	raycasting->data->horizontal = false;
	draw_game(raycasting, distance, \
	raycasting->angle - raycasting->data->angle, i);
}
