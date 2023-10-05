#include "cub3D.h"

static void draw_north_vector(t_draw_vector *draw_vector);

void	draw_col(t_draw_vector *draw_vector, double distance);

#include "stdio.h"

void draw_direction_vector(t_data *data, t_draw *draw)
{
	int	i = 1;
	t_draw_vector	draw_vector;

	draw_vector.x = SIZE_X - 1;
	draw_vector.draw = draw;
	draw_vector.data = data;
	draw_vector.px_map = data->px_map;
	draw_vector.py_map = data->py_map;
	while (i <= SIZE_X)
	{
		draw_vector.decalage = ((float)i / SIZE_X) + 1;
		draw_vector.c_angle = cosf((draw_vector.decalage * (M_PI / 3)) + \
		data->angle);
		draw_vector.s_angle = -sinf((draw_vector.decalage * (M_PI / 3) + \
		data->angle));
		draw_vector.decalage = (draw_vector.decalage - 1.5) * (M_PI / 3);
		draw_north_vector(&draw_vector);
		i++;
		draw_vector.x--;
	}
}

static void draw_north_vector(t_draw_vector *draw_vector)
{
	int x;
	int y;
	float t;
	double		distance;

	t = 0;
	x = draw_vector->px_map + t * draw_vector->c_angle;
	y = draw_vector->py_map + t * draw_vector->s_angle;
	distance = 0;
	while (1)
	{
		if (draw_vector->data->map[y / SQUARE_SIZE][x / SQUARE_SIZE] == '1' || \
		draw_vector->data->map[(y + 1) / SQUARE_SIZE][x / SQUARE_SIZE] == '1' \
		|| draw_vector->data->map[y / SQUARE_SIZE][(x + 1)/ SQUARE_SIZE] == '1')
			break ;	
		t += 1;
		x = draw_vector->px_map + t * draw_vector->c_angle / 10;
		y = draw_vector->py_map + t * draw_vector->s_angle / 10;
		distance += 0.1;
	}
	draw_col(draw_vector, distance);
}

void	draw_col(t_draw_vector *draw_vector, double distance)
{
	long	y;
	long	size_wall;
	long	half_size_wall;

	if (distance == 0)
		distance = 0.2;
	size_wall = (1 / (distance  * cos(draw_vector->decalage))) * 40000;
	half_size_wall = size_wall / 2;
	y = 0;
	while (y < ((SIZE_Y / 2) - half_size_wall))
	{
		my_mlx_pixel_put(draw_vector->draw, draw_vector->x, y, draw_vector->data->celling);
		y++;
	}
	y = (SIZE_Y / 2) - half_size_wall;
	while (y <= ((SIZE_Y / 2) + half_size_wall))
	{
		my_mlx_pixel_put(draw_vector->draw, draw_vector->x, y, H_GREY);
		y++;
	}
	while (y < SIZE_Y)
	{
		my_mlx_pixel_put(draw_vector->draw, draw_vector->x, y, draw_vector->data->floor);
		y++;
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
