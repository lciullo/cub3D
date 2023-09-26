#include "cub3D.h"

static void draw_north_vector(t_data *data, t_draw *draw, int x_start, int y_start, double c_angle, double s_angle, int size, int dir);

void draw_direction_vector(t_data *data, t_draw *draw)
{
	//int square_half_size;

	//square_half_size = SQUARE_SIZE / 4;
	draw_north_vector(data, draw, data->px_map, data->py_map, cosf(M_PI_2 + data->angle), -sinf(M_PI_2 + data->angle), 277, 0);
	draw_north_vector(data, draw, data->px_map, data->py_map, cos((2 * M_PI / 3) + data->angle), -sin((2 * M_PI / 3) + data->angle), (277 / cos((M_PI * 30) / 180)), 1);
	draw_north_vector(data, draw, data->px_map, data->py_map, cos((M_PI / 3) + data->angle), -sin((M_PI / 3) + data->angle), (277 / cos((M_PI * 30) / 180)), 1);
}

void find_direction(t_data *data)
{
	if (data->N == true)
		data->N = false;
	else if (data->S == true)
	{
		data->S = false;
		data->angle += (M_PI * 180) / 180;
	}
	else if (data->W == true)
	{
		data->W = false;
		data->angle += M_PI_2;
	}
	else if (data->E == true)
	{
		data->E = false;
		data->angle -= M_PI_2;
	}
}

#include <stdio.h>

static void draw_north_vector(t_data *data, t_draw *draw, int x_start, int y_start, double c_angle, double s_angle, int size, int dir)
{
	int x;
	int y;
	float t;

	t = 0;
	x = x_start + t * c_angle;
	y = y_start + t * s_angle;
	(void)size;
	while (1)
	{
		if (data->map[y / SQUARE_SIZE][x / SQUARE_SIZE] == '1')
			break ;
		my_mlx_pixel_put(draw, x, y, H_GREEN);
		t = t + 0.001;
		x = x_start + t * c_angle;
		y = y_start + t * s_angle;
	}
	if (dir == 0)
	{
		data->x_dir = (x - x_start) * 0.1;
		data->y_dir = (y - y_start) * 0.1;
	}
}
