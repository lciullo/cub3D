#include "cub3D.h"

static int	find_len_max(int *len_line);

void    mini_map(t_data *data, t_draw *draw)
{
	int	x;
	int	y;
	int	x_square;
	int	y_square;
	int	len_max;

	y = 0;
	y_square = 0;
	len_max = find_len_max(data->len_line);
	ft_dprintf(1, "len_max : %d\n", len_max);
	while (data->map[y])
	{
		x = 0;
		x_square = 0;
		while (data->map[y][x])
		{
			if (data->map[y][x] == '1' || data->map[y][x] == ' ')
				draw_square(draw, x_square, y_square, H_PINK, 10);
			else if (data->map[y][x] == '0')
				draw_square(draw, x_square, y_square, H_GREY, 10);
			else if (data->map[y][x] == 'N' || data->map[y][x] == 'S' || data->map[y][x] == 'W' || data->map[y][x] == 'E')
				draw_square(draw, x_square, y_square, H_PURPLE, 10);
			// else if (x < len_max)
			// {
			// 	while (x < len_max)
			// 	{
			// 		draw_square(draw, x_square, y_square, H_PINK, 10);
			// 		x++;
			// 		x_square += 10;
			// 	}
			// 	break ;
			// }
			x++;
			x_square += 10;
		}
		y++;
		y_square += 10;
	}
}

static int	find_len_max(int *len_line)
{
	int	i;
	int	len_max;

	i = 0;
	len_max = 0;
	while (len_line[i])
	{
		ft_dprintf(1, "len_line[%d] : %d\n", i, len_line[i]);
		// if (i == 0)
		// 	len_max = len_line[i];
		// else if (len_line[i] > len_max)
		// 	len_max = len_line[i];
		i++;
	}
	return (len_max);
}