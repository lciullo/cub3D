#include "cub3D.h"

static void set_start_direction(t_data *data);

void set_start_value(t_data *data)
{
	data->px_map = (data->xf_p * SQUARE_SIZE);
	data->py_map = (data->yf_p * SQUARE_SIZE);
	set_start_direction(data);
}

static void set_start_direction(t_data *data)
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