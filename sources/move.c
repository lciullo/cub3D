#include "cub3D.h"

void	move_up(t_data *data)
{
	data->square_y += data->y_dir;
	data->square_x += data->x_dir;
}

void	move_down(t_data *data)
{
	data->square_y -= data->y_dir;
	data->square_x -= data->x_dir;
}

void	move_left(t_data *data)
{
	data->square_x -= (data->x_dir * cosf((M_PI / 2))) - (data->y_dir * sinf((M_PI / 2)));
	data->square_y -= (data->x_dir * sinf((M_PI / 2))) + (data->y_dir * cosf((M_PI / 2)));
}

void	move_right(t_data *data)
{
	data->square_x += (data->x_dir * cosf((M_PI / 2))) - (data->y_dir * sinf((M_PI / 2)));
	data->square_y += (data->x_dir * sinf((M_PI / 2))) + (data->y_dir * cosf((M_PI / 2)));
}