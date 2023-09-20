#include "cub3D.h"

static void	draw_north_vector(t_data *data, t_draw *draw);
static void	draw_south_vector(t_data *data, t_draw *draw);
static void	draw_east_vector(t_data *data, t_draw *draw);
static void	draw_west_vector(t_data *data, t_draw *draw);

void	draw_direction_vector(t_data *data, t_draw *draw)
{
	if (data->N == true)
		draw_north_vector(data, draw);
	else if (data->S == true)
		draw_south_vector(data, draw);
	else if (data->E == true)
		draw_east_vector(data, draw);
	else if (data->W == true)
		draw_west_vector(data, draw);
}

static void	draw_north_vector(t_data *data, t_draw *draw)
{
	int x;
	int y;

	x = data->square_x + 40;
	y = data->square_y;
	while (y > 25)
	{
		my_mlx_pixel_put(draw, x, y, H_GREEN);
		y--;
	}
}

static void	draw_south_vector(t_data *data, t_draw *draw)
{
	int x;
	int y;

	x = data->square_x + 40;
	y = data->square_y + 80;
	while (y < (SIZE_Y - 25))
	{
		my_mlx_pixel_put(draw, x, y, H_GREEN);
		y++;
	}
}

static void	draw_east_vector(t_data *data, t_draw *draw)
{
	int x;
	int y;

	x = data->square_x + 80;
	y = data->square_y + 40;
	while (x < (SIZE_X - 25))
	{
		my_mlx_pixel_put(draw, x, y, H_GREEN);
		x++;
	}
}

static void	draw_west_vector(t_data *data, t_draw *draw)
{
	int x;
	int y;

	x = data->square_x;
	y = data->square_y + 40;
	while (x > 25)
	{
		my_mlx_pixel_put(draw, x, y, H_GREEN);
		x--;
	}
}