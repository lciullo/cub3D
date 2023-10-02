#include "cub3D.h"

#include "stdio.h"

void	move_up(t_data *data)
{
	data->py_map += 10 * sin(data->angle - M_PI_2);
	data->px_map += 10 * cos(data->angle + M_PI_2);
	//printf("%f\n", data->angle);
}

void	move_down(t_data *data)
{
	data->py_map += 10 * sin(data->angle + M_PI_2);
	data->px_map += 10 * cos(data->angle - M_PI_2);
}

void	move_left(t_data *data)
{
	data->py_map += 10 * sin(data->angle);
	data->px_map -= 10 * cos(data->angle);
}

void	move_right(t_data *data)
{
	data->py_map -= 10 * sin(data->angle);
	data->px_map += 10 * cos(data->angle);
}