#include "cub3D.h"

void	move_up(t_data *data)
{
	data->square_y -= data->gap;
}

void	move_down(t_data *data)
{
	data->square_y += data->gap;
}

void	move_left(t_data *data)
{
	data->square_x -= data->gap;
}

void	move_right(t_data *data)
{
	data->square_x+= data->gap;
}