#include "cub3D.h"

void	draw_ceilling_and_floor(long *y, t_raycasting *raycasting, int y_max, int color);
static double get_wall_distance(t_raycasting *raycasting);
void	draw_game(t_raycasting *raycasting, double distance);
void	init_angle_struct_raycasting(int i, t_raycasting *raycasting, t_data *data);
bool	did_we_reach_a_wall(t_raycasting *raycasting, int x, int y);
void	draw_wall(long *y, t_raycasting *raycasting, int y_max, int color);

void	init_angle_struct_raycasting(int i, t_raycasting *raycasting, t_data *data)
{
	raycasting->shift = ((float)i / SIZE_X) + 1;
	raycasting->cos_angle = cosf(raycasting->shift * (M_PI / 3) + data->angle);
	raycasting->sin_angle = -sinf(raycasting->shift * (M_PI / 3) + data->angle);
	raycasting->shift = (raycasting->shift - 1.5) * (M_PI / 3);
}

void raycasting(t_data *data, t_draw *draw)
{
	int				i;
	double			distance;
	t_raycasting	raycasting;

	i = 1;
	init_struct_raycasting(&raycasting, data, draw);
	while (i <= SIZE_X)
	{
		init_angle_struct_raycasting(i, &raycasting, data);
		distance = get_wall_distance(&raycasting);
		draw_game(&raycasting, distance);
		i++;
		raycasting.x--;
	}
}

static double get_wall_distance(t_raycasting *raycasting)
{
	int x;
	int y;
	float t;
	double		distance;

	t = 0;
	x = raycasting->data->px_map + t * raycasting->cos_angle;
	y = raycasting->data->py_map + t * raycasting->sin_angle;
	distance = 0;
	while (1)
	{
		if (did_we_reach_a_wall(raycasting, x, y) == true)
			break ;	
		t += 1;
		x = raycasting->data->px_map + t * raycasting->cos_angle / 10;
		y = raycasting->data->py_map + t * raycasting->sin_angle / 10;
		distance += 0.1;
	}
	return (distance);
}

bool	did_we_reach_a_wall(t_raycasting *raycasting, int x, int y)
{
	if (raycasting->data->map[y / SQUARE_SIZE][x / SQUARE_SIZE] == '1' || \
	raycasting->data->map[(y + 1) / SQUARE_SIZE][x / SQUARE_SIZE] == '1' \
	|| raycasting->data->map[y / SQUARE_SIZE][(x + 1)/ SQUARE_SIZE] == '1')
		return (true);
	return (false);
}

void	draw_game(t_raycasting *raycasting, double distance)
{
	long	y;
	long	size_wall;
	long	half_size_wall;

	if (distance == 0)
		distance = 0.2;
	size_wall = (1 / (distance  * cos(raycasting->shift))) * 40000;
	half_size_wall = size_wall / 2;
	y = 0;
	draw_ceilling_and_floor(&y, raycasting, ((SIZE_Y / 2) - half_size_wall), raycasting->data->celling);
	draw_wall(&y, raycasting, ((SIZE_Y / 2) + half_size_wall), H_GREY);
	draw_ceilling_and_floor(&y, raycasting, SIZE_Y, raycasting->data->floor);
}

void	draw_wall(long *y, t_raycasting *raycasting, int y_max, int color)
{
	while (*y <= y_max)
	{
		my_mlx_pixel_put(raycasting->draw, raycasting->x, *y, color);
		*y = *y +1;
	}
}
void	draw_ceilling_and_floor(long *y, t_raycasting *raycasting, int y_max, int color)
{
	while (*y < y_max)
	{
		my_mlx_pixel_put(raycasting->draw, raycasting->x, *y, color);
		*y = *y + 1;
	}
}