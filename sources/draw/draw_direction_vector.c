#include "cub3D.h"

static void draw_north_vector(t_data *data, t_draw *draw, int x_start, int y_start, double c_angle, double s_angle, int nbr_r, int decalage);

void draw_col(t_draw *draw, double distance, int x);

#include "stdio.h"

void draw_direction_vector(t_data *data, t_draw *draw)
{
	int	i = 1;
	float	decalage;

	while (i < SIZE_X)
	{
		decalage = ((float)i / SIZE_X) + 1;
		draw_north_vector(data, draw, data->px_map, data->py_map, cosf((decalage * M_PI / 3) + data->angle), -sinf((decalage * M_PI / 3) + data->angle), i, decalage);
		i++;
	}
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

static void draw_north_vector(t_data *data, t_draw *draw, int x_start, int y_start, double c_angle, double s_angle, int nbr_r, int decalage)
{
	int x;
	int y;
	float t;
	int		last_x;
	int		last_y;
	int		first_x;
	int		first_y;
	double		distance;
	double		distance_2;

	t = 0;
	x = x_start + t * c_angle;
	y = y_start + t * s_angle;
	last_x = 0;
	last_y = 0;
	first_x = x;
	first_y = y;
	(void)draw;
	while (1)
	{
		//(y % SQUARE_SIZE == 0 || x % SQUARE_SIZE == 0) && 
		if (data->map[y / SQUARE_SIZE][x / SQUARE_SIZE] == '1')
			break ;
		//my_mlx_pixel_put(draw, x, y, H_GREEN);
		t += 1;
		x = x_start + t * c_angle;
		y = y_start + t * s_angle;
		last_x = x;
		last_y = y;
	}
	distance = sqrt(pow((last_x - first_x), 2) + pow((last_y - first_y), 2));
	distance_2 = distance * cos(data->angle - (decalage * M_PI / 3));
	draw_col(draw, distance_2, nbr_r - 1);
}

void	draw_col(t_draw *draw, double distance, int x)
{
	int	y;
	int	size_wall;
	int	half_size_wall;

	size_wall = (1 / distance) * 40000;
	half_size_wall = size_wall / 2;
	y = SIZE_Y / 2;
	while (y > ((SIZE_Y / 2) - half_size_wall))
	{
		my_mlx_pixel_put(draw, x, y, H_GREY);
		y--;
	}
	y = SIZE_Y / 2;
	while (y < ((SIZE_Y / 2) + half_size_wall))
	{
		my_mlx_pixel_put(draw, x, y, H_GREY);
		y++;
	}
}