#include "cub3D.h"

static int	find_len_max(int *len_line, int size_map);

void    mini_map(t_data *data, t_draw *draw)
{
	int	x;
	int	y;
	int	x_square;
	int	y_square;
	int	len_max;
	int	size_square;

	y = 0;
	y_square = 0;
	len_max = find_len_max(data->len_line, data->size_map);
	size_square = SIZE_X / len_max;
	while (data->map[y])
	{
		x = 0;
		x_square = 0;
		while (data->map[y][x])
		{
			if (data->map[y][x] == '1' || data->map[y][x] == ' ')
				draw_square(draw, x_square, y_square, H_PINK, size_square);
			else if (data->map[y][x] == '0')
				draw_square(draw, x_square, y_square, H_GREY, size_square);
			else if (data->map[y][x] == 'N' || data->map[y][x] == 'S' || data->map[y][x] == 'W' || data->map[y][x] == 'E')
				draw_square(draw, data->square_x, data->square_y, H_PURPLE, size_square);
			x++;
			x_square += size_square;
		}
		if (x < len_max)
		{
			while (x < len_max)
			{
				draw_square(draw, x_square, y_square, H_PINK, size_square);
				x++;
				x_square += size_square;
			}
		}
		y++;
		y_square += size_square;
	}
}

static int	find_len_max(int *len_line, int size_map)
{
	int	i;
	int	len_max;

	i = 0;
	len_max = 0;
	while (i < size_map)
	{
		if (i == 0)
		 	len_max = len_line[i];
		else if (len_line[i] > len_max)
		 	len_max = len_line[i];
		i++;
	}
	return (len_max);
}