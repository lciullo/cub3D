#include "cub3D.h"

void init_struct(t_data *data, t_parsing *utils)
{
	data->map = NULL;
	data->directions = NULL;
	data->colors = NULL;
	data->len_line = 0;
	data->size_map = 0;
	data->N = false;
	data->S = false;
	data->E = false;
	data->W = false;
	utils->nb_player = 0;
	utils->nb_wall = 0;
	utils->nb_space = 0;
	return ;
}