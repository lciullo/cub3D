#include "cub3D.h"

static void draw_north_vector(t_data *data, t_draw *draw, int x_start, int y_start, double c_angle, double s_angle, int nbr_r, float decalage);

void	draw_col(t_draw *draw, double distance, int x, float decalage);

#include "stdio.h"

void draw_direction_vector(t_data *data, t_draw *draw)
{
	int	i = 1;
	int	x;
	float	decalage;

	x = SIZE_X;
	while (i < SIZE_X)
	{
		decalage = ((float)i / SIZE_X) + 1;
		draw_north_vector(data, draw, data->px_map, data->py_map, cosf((decalage * (M_PI / 3)) + data->angle), -sinf((decalage * (M_PI / 3) + data->angle)), x, (decalage - 1.5) * (M_PI / 3));
		i++;
		x--;

	}
}

static void draw_north_vector(t_data *data, t_draw *draw, int x_start, int y_start, double c_angle, double s_angle, int nbr_r, float decalage)
{
	int x;
	int y;
	float t;
	double		distance;

	t = 0;
	x = x_start + t * c_angle;
	y = y_start + t * s_angle;
	distance = 0;
	while (1)
	{
		//(y % SQUARE_SIZE == 0 || x % SQUARE_SIZE == 0) && 
		if (data->map[y / SQUARE_SIZE][x / SQUARE_SIZE] == '1')
			break ;
		t += 1;
		x = x_start + t * c_angle / 10;
		y = y_start + t * s_angle / 10;
		distance += 0.1;
	}
	draw_col(draw, distance, nbr_r - 1, decalage);
}

void	draw_col(t_draw *draw, double distance, int x, float decalage)
{
	int	y;
	int	i = 0;
	int	size_wall;
	int	half_size_wall;

	// (void)decalage;
	size_wall = (1 / (distance * cos(decalage))) * 40000;
	half_size_wall = size_wall / 2;
	y = (SIZE_Y / 2) - half_size_wall;
	while (y < ((SIZE_Y / 2) + half_size_wall))
	{
		my_mlx_pixel_put(draw, x, y, H_GREY);
		y++;
		i++;
	}
// 	printf("%d %d %f\n", i, size_wall, decalage);
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