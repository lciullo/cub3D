#include "cub3D.h"

#include "stdio.h"

void	move_up(t_data *data)
{
	float	added_value_y;
	float	added_value_x;
	float	map_y;
	float	map_x;

	added_value_y = 10 * sin(data->angle - M_PI_2);
	added_value_x = 10 * cos(data->angle + M_PI_2);
	map_y = data->py_map + added_value_y;
	map_x = data->px_map + added_value_x;
	if (data->map[(int)(((map_y) / SQUARE_SIZE) + 0.2)][(int)((((map_x) / SQUARE_SIZE) - 0.2))] != '1' && \
	data->map[(int)(((map_y) / SQUARE_SIZE) - 0.2)][(int)((((map_x) / SQUARE_SIZE) + 0.2))] != '1')
	{
		data->py_map += added_value_y;
		data->px_map += added_value_x;
	}
}

void	move_down(t_data *data)
{
	float	added_value_y;
	float	added_value_x;
	float	map_y;
	float	map_x;

	added_value_y = 10 * sin(data->angle + M_PI_2);
	added_value_x = 10 * cos(data->angle - M_PI_2);
	map_y = data->py_map + added_value_y;
	map_x = data->px_map + added_value_x;
	if (data->map[(int)(((map_y) / SQUARE_SIZE) - 0.2)][(int)((((map_x) / SQUARE_SIZE)) - 0.2)] != '1' && \
	data->map[(int)(((map_y) / SQUARE_SIZE) + 0.2)][(int)((((map_x) / SQUARE_SIZE)) + 0.2)] != '1')
	{
		data->py_map += added_value_y;
		data->px_map += added_value_x;
	}
}

void	move_left(t_data *data)
{
	float	added_value_y;
	float	added_value_x;
	float	map_y;
	float	map_x;

	added_value_y = 10 * sin(data->angle);
	added_value_x = 10 * cos(data->angle);
	map_y = data->py_map + added_value_y;
	map_x = data->px_map - added_value_x;
	if (data->map[(int)(((map_y) / SQUARE_SIZE) - 0.2)][(int)(((map_x) / SQUARE_SIZE) + 0.2)] != '1' && \
	data->map[(int)(((map_y) / SQUARE_SIZE) + 0.2)][(int)(((map_x) / SQUARE_SIZE) - 0.2)] != '1')
	{
		data->py_map += added_value_y;
		data->px_map -= added_value_x;
	}
}

void	move_right(t_data *data)
{
	float	added_value_y;
	float	added_value_x;
	float	map_y;
	float	map_x;

	added_value_y = 10 * sin(data->angle);
	added_value_x = 10 * cos(data->angle);
	map_y = data->py_map - added_value_y;
	map_x = data->px_map + added_value_x;
	if (data->map[(int)(map_y / (SQUARE_SIZE) - 0.2)][(int)((map_x / (SQUARE_SIZE)) - 0.2)] != '1' &&
	data->map[(int)((map_y / (SQUARE_SIZE)) + 0.2)][(int)(map_x / (SQUARE_SIZE) + 0.2)] != '1')
	{
		data->py_map -= added_value_y;
		data->px_map += added_value_x;
	}
}
