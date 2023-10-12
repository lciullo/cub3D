/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cllovio <cllovio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 14:36:07 by cllovio           #+#    #+#             */
/*   Updated: 2023/10/12 15:17:11 by cllovio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

// static double	get_wall_distance(t_raycasting *raycasting);
static void		init_angle_struct_raycasting(int i, t_raycasting *raycasting, \
				t_data *data);
// static bool		did_we_reach_a_wall(t_raycasting *raycasting, float x, float y);
void	horizontal_collision(t_raycasting *raycasting, t_col_point *horizontal);
void	vertical_collision(t_raycasting *raycasting, t_col_point *vertical);
void	horizontal_collision_pos(t_raycasting *raycasting, t_col_point *horizontal);
void	vertical_collision_pos(t_raycasting *raycasting, t_col_point *vertical);

#include <stdio.h>

void	raycasting(t_data *data, t_draw *draw)
{
	int				i;
	t_col_point		vertical;
	t_col_point		horizontal;
	t_raycasting	raycasting;

	i = 1;
	
	init_struct_raycasting(&raycasting, data, draw);
	while (i <= SIZE_X)
	{
		init_angle_struct_raycasting(i, &raycasting, data);
		printf("%f\n", raycasting.cos_angle);
		if (raycasting.sin_angle < 0)
			horizontal_collision(&raycasting, &horizontal);
		else if (raycasting.sin_angle >= 0)
			horizontal_collision_pos(&raycasting, &horizontal);
		if (raycasting.cos_angle >= 0)
			vertical_collision(&raycasting, &vertical);
		else if (raycasting.cos_angle < 0)
			vertical_collision_pos(&raycasting, &vertical);
		if (horizontal.distance < vertical.distance)
			my_mlx_pixel_put(raycasting.draw, (horizontal.x / 2), (horizontal.y / 2), H_WHITE);
		else
			my_mlx_pixel_put(raycasting.draw, (vertical.x / 2), (vertical.y / 2), H_GREEN);
		// draw_game(&raycasting, distance);
		i++;
		// raycasting.x--;
	}
}

void	vertical_collision(t_raycasting *raycasting, t_col_point *vertical)
{
	float	y;
	float	x;
	float	pow_x;
	float	pow_y;
	float	x_shift;
	float	distance;

	y = 0;
	x = 0;
	pow_x = 0;
	pow_y = 0;
	x_shift = 0;
	distance = 0;
	while (x <= raycasting->data->px_map)
		x += SQUARE_SIZE;
	x -= SQUARE_SIZE;
	x_shift = (x - raycasting->data->px_map) / raycasting->cos_angle;
	y = raycasting->data->py_map + x_shift * raycasting->sin_angle;
	pow_x = pow((raycasting->data->px_map - x), 2);
	pow_y = pow((raycasting->data->py_map - y), 2);
	vertical->x = x;
	vertical->y = y;
	vertical->distance = sqrt(pow_x + pow_y);
}

void	vertical_collision_pos(t_raycasting *raycasting, t_col_point *vertical)
{
	float	y;
	float	x;
	float	pow_x;
	float	pow_y;
	float	x_shift;
	float	distance;

	y = 0;
	x = 0;
	pow_x = 0;
	pow_y = 0;
	x_shift = 0;
	distance = 0;;
	while (x <= raycasting->data->px_map)
		x += SQUARE_SIZE;
	x_shift = (x - raycasting->data->px_map) / raycasting->cos_angle;
	y = raycasting->data->py_map + x_shift * raycasting->sin_angle;
	pow_x = pow((raycasting->data->px_map - x), 2);
	pow_y = pow((raycasting->data->py_map - y), 2);
	vertical->x = x;
	vertical->y = y;
	vertical->distance = sqrt(pow_x + pow_y);
}

void	horizontal_collision(t_raycasting *raycasting, t_col_point *horizontal)
{
	float	y;
	float	x;
	float	pow_x;
	float	pow_y;
	float	y_shift;
	float	distance;
	
	y = 0;
	x = 0;
	pow_x = 0;
	pow_y = 0;
	y_shift = 0;
	distance = 0;
	while (y <= raycasting->data->py_map)
		y += SQUARE_SIZE;
	y_shift = (y - raycasting->data->py_map) / raycasting->sin_angle;
	x = raycasting->data->px_map + y_shift * raycasting->cos_angle;
	pow_x = pow((raycasting->data->px_map - x), 2);
	pow_y = pow((raycasting->data->py_map - y), 2);
	distance = sqrt(pow_x + pow_y);
	horizontal->x = x;
	horizontal->y = y;
	horizontal->distance = sqrt(pow_x + pow_y);
}

void	horizontal_collision_pos(t_raycasting *raycasting, t_col_point *horizontal)
{
	float	y;
	float	x;
	float	pow_x;
	float	pow_y;
	float	y_shift;
	float	distance;
	
	y = 0;
	x = 0;
	pow_x = 0;
	pow_y = 0;
	y_shift = 0;
	distance = 0;
	while (y <= raycasting->data->py_map)
		y += SQUARE_SIZE;
	y -= SQUARE_SIZE;
	y_shift = (y - raycasting->data->py_map) / raycasting->sin_angle;
	x = raycasting->data->px_map + y_shift * raycasting->cos_angle;
	pow_x = pow((raycasting->data->px_map - x), 2);
	pow_y = pow((raycasting->data->py_map - y), 2);
	horizontal->x = x;
	horizontal->y = y;
	horizontal->distance = sqrt(pow_x + pow_y);
}

static void	init_angle_struct_raycasting(int i, t_raycasting *raycasting, \
			t_data *data)
{
	data->collision_cor[0] = 0;
	data->collision_cor[1] = 0;
	raycasting->shift = ((float)i / SIZE_X) + 1;
	raycasting->cos_angle = -cosf(raycasting->shift * (M_PI / 3) + data->angle);
	raycasting->sin_angle = sinf(raycasting->shift * (M_PI / 3) + data->angle);
	raycasting->shift = (raycasting->shift - 1.5) * (M_PI / 3);
}

/*static bool	did_we_reach_a_wall(t_raycasting *raycasting, float x, float y)
{
	if (raycasting->data->map[(int)(y / SQUARE_SIZE)][(int)(x / SQUARE_SIZE)] == '1' || \
	raycasting->data->map[(int)((y + 1) / SQUARE_SIZE)][(int)(x / SQUARE_SIZE)] == '1' \
	|| raycasting->data->map[(int)(y / SQUARE_SIZE)][(int)((x + 1) / SQUARE_SIZE)] == '1')
		return (true);
	return (false);
}*/
