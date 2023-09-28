#include "cub3D.h"

static void draw_north_vector(t_data *data, t_draw *draw, int x_start, int y_start, double c_angle, double s_angle, int nbr_r, float b_carre);

void draw_col(t_draw *draw, t_data *data, double distance, float distance_screen, int vision_center, int x);

#include "stdio.h"

void draw_direction_vector(t_data *data, t_draw *draw)
{
	int	i = 1;
	float	decalage;
	float	b_carre;

	while (i < SIZE_X)
	{
		decalage = ((float)i / SIZE_X) + 1;
		b_carre = pow((SIZE_X / 2) / tan((decalage + (M_PI) / 3) + data->angle), 2);
		draw_north_vector(data, draw, data->px_map, data->py_map, cosf((decalage * M_PI / 3) + data->angle), -sinf((decalage * M_PI / 3) + data->angle), i, b_carre);
		//draw_north_vector(data, draw, data->px_map, data->py_map, cosf(M_PI_2 + data->angle), -sinf(M_PI_2 + data->angle));
		i++;
	}
	//draw_north_vector(data, draw, data->px_map, data->py_map, cosf((2 * M_PI / 3) + data->angle), -sin((2 * M_PI / 3) + data->angle));
	//draw_north_vector(data, draw, data->px_map, data->py_map, cos((1 * M_PI / 3) + data->angle), -sin((1 * M_PI / 3) + data->angle));
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

static void draw_north_vector(t_data *data, t_draw *draw, int x_start, int y_start, double c_angle, double s_angle, int nbr_r, float b_carre)
{
	int x;
	int y;
	float t;
	int		last_x;
	int		last_y;
	int		first_x;
	int		first_y;
	double		distance;

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
	draw_col(draw, data, distance, sqrt(pow(SIZE_X / 2, 2) + b_carre), (SIZE_Y / 2), nbr_r - 1);
	//pas faire en fonction de l'angle
}

void draw_col(t_draw *draw, t_data *data, double distance, float distance_screen, int vision_center, int x)
{
	int	c_size;
	float	true_wall_size;
	int	y;
	int	y_max;

	true_wall_size = (SIZE_Y / distance) * distance_screen;
	c_size = vision_center - (true_wall_size / 2);
	y = c_size;
	y_max = y + true_wall_size;
	(void)data;
	printf("%f %f %f\n", distance, true_wall_size, distance_screen);
	while (y <= y_max)
	{
		my_mlx_pixel_put(draw, x, y, H_GREY);
		y++;
	}
}
