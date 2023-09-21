#include "cub3D.h"

static void	draw_north_vector(t_draw *draw, int x_start, int y_start, double c_angle, double s_angle, int size);

void	draw_direction_vector(t_data *data, t_draw *draw)
{
	if (data->N == true)
	{
		draw_north_vector(draw, (data->square_x + 40), data->square_y, cos(M_PI_2), -sin(M_PI_2), 277);
		draw_north_vector(draw, (data->square_x + 40), (data->square_y - (160 / tan((M_PI * 30) / 180))), cos(M_PI), sin(M_PI), 160);
		draw_north_vector(draw, (data->square_x + 40), (data->square_y - (160 / tan((M_PI * 30) / 180))), cos(0), sin(0), 160);
		draw_north_vector(draw, (data->square_x + 40), data->square_y, cos(2 * M_PI / 3), -sin(2 * M_PI / 3), (277 / cos((M_PI * 30) / 180)));
		draw_north_vector(draw, (data->square_x + 40), data->square_y, cos(M_PI / 3), -sin(M_PI / 3), (277 / cos((M_PI * 30) / 180)));
	}
	else if (data->S == true)
	{
		draw_north_vector(draw, (data->square_x + 40), (data->square_y + 80), cos(M_PI_2), sin(M_PI_2), 277);
		draw_north_vector(draw, (data->square_x + 40 ), ((data->square_y + 80) + (160 / tan((M_PI * 30) / 180))), cos(M_PI), sin(M_PI), 160);
		draw_north_vector(draw, (data->square_x + 40), ((data->square_y + 80) + (160 / tan((M_PI * 30) / 180))), cos(0), sin(0), 160);
		draw_north_vector(draw, (data->square_x + 40), (data->square_y + 80), cos(4 * M_PI / 3), -sin(4 * M_PI / 3), (277 / cos((M_PI * 30) / 180)));
		draw_north_vector(draw, (data->square_x + 40), (data->square_y + 80), cos(5 * M_PI / 3), -sin(5 * M_PI / 3), (277 / cos((M_PI * 30) / 180)));
	}
	else if (data->E == true)
	{
		draw_north_vector(draw, (data->square_x + 80), (data->square_y + 40), cos(0), sin(0), 277);
		draw_north_vector(draw, ((data->square_x + 80) + (160 / tan((M_PI * 30) / 180))), (data->square_y + 40), cos(M_PI_2), sin(M_PI_2), 160);
		draw_north_vector(draw, ((data->square_x + 80) + (160 / tan((M_PI * 30) / 180))), (data->square_y + 40), cos(3 * M_PI_2), sin(3 * M_PI_2), 160);
		draw_north_vector(draw, (data->square_x + 80), (data->square_y + 40), cos(M_PI / 6), sin(M_PI / 6), (277 / cos((M_PI * 30) / 180)));
		draw_north_vector(draw, (data->square_x + 80), (data->square_y + 40), cos(11 * M_PI / 6), sin(11 * M_PI / 6), (277 / cos((M_PI * 30) / 180)));
	}
	else if (data->W == true)
	{
		draw_north_vector(draw, data->square_x, (data->square_y + 40), cos(M_PI), sin(M_PI), 277);
		draw_north_vector(draw, (data->square_x - (160 / tan((M_PI * 30) / 180))), (data->square_y + 40), cos(M_PI_2), sin(M_PI_2), 160);
		draw_north_vector(draw, (data->square_x - (160 / tan((M_PI * 30) / 180))), (data->square_y + 40), cos(3 * M_PI_2), sin(3 * M_PI_2), 160);
		draw_north_vector(draw, data->square_x, (data->square_y + 40), cos(5 * M_PI / 6), sin(5 * M_PI / 6), (277 / cos((M_PI * 30) / 180)));
		draw_north_vector(draw, data->square_x, (data->square_y + 40), cos(7 * M_PI / 6), sin(7 * M_PI / 6), (277 / cos((M_PI * 30) / 180)));
	}

}

static void	draw_north_vector(t_draw *draw, int x_start, int y_start, double c_angle, double s_angle, int size)
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
}
