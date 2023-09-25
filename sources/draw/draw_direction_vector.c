#include "cub3D.h"

static void	draw_north_vector(t_data *data, t_draw *draw, int x_start, int y_start, double c_angle, double s_angle, int size);

void	draw_direction_vector(t_data *data, t_draw *draw)
{
	int	square_half_size;

	square_half_size = (SIZE_X / find_len_max(data->len_line, data->size_map)) / 2;
	draw_north_vector(data, draw, (data->square_x + square_half_size), (data->square_y + square_half_size), cosf(M_PI_2 + data->angle), -sinf(M_PI_2 + data->angle), 277);
	//draw_north_vector(draw, (data->square_x + square_half_size), ((data->square_y + square_half_size) - (160 / tan((M_PI * 30) / 180))), cos(M_PI + data->angle), sin(M_PI + data->angle), 160);
	//draw_north_vector(draw, (data->square_x + square_half_size), ((data->square_y + square_half_size) - (160 / tan((M_PI * 30) / 180))), cos(0 + data->angle), sin(0 + data->angle), 160);
	//draw_north_vector(draw, (data->square_x + square_half_size), (data->square_y + square_half_size), cos((2 * M_PI / 3) + data->angle), -sin((2 * M_PI / 3) + data->angle), (277 / cos((M_PI * 30) / 180)));
	//draw_north_vector(draw, (data->square_x + square_half_size), (data->square_y + square_half_size), cos((M_PI / 3) + data->angle), -sin((M_PI / 3) + data->angle), (277 / cos((M_PI * 30) / 180)));
}

static void	draw_north_vector(t_data *data, t_draw *draw, int x_start, int y_start, double c_angle, double s_angle, int size)
{
	int	x; 
	int	y;
	float	t;

	t = 0;
	x = x_start + t * c_angle;
	y = y_start + t * s_angle;
	while (t < size)
	{
		my_mlx_pixel_put(draw, x, y, H_GREEN);
		t = t + 0.001;
		x = x_start + t * c_angle;
		y = y_start + t * s_angle;
	}
	data->x_dir = (x - x_start) * 0.1;
	data->y_dir = (y - y_start) * 0.1;
}
