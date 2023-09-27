#include "cub3D.h"

void	move_up(t_data *data)
{
	data->py_map += data->y_dir;
	data->px_map += data->x_dir;
}

void	move_down(t_data *data)
{
	data->py_map -= data->y_dir;
	data->px_map -= data->x_dir;
}

void	move_left(t_data *data)
{
	data->px_map -= (data->x_dir * cosf((M_PI_2))) - (data->y_dir * sinf((M_PI_2)));
	data->py_map -= (data->x_dir * sinf((M_PI_2))) + (data->y_dir * cosf((M_PI_2)));
}

void	move_right(t_data *data)
{
	data->px_map += (data->x_dir * cosf((M_PI_2))) - (data->y_dir * sinf((M_PI_2)));
	data->py_map += (data->x_dir * sinf((M_PI_2))) + (data->y_dir * cosf((M_PI_2)));
}