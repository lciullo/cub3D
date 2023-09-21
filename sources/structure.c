#include "cub3D.h"

void init_struct(t_data *data, t_parsing *utils)
{
    data->map = NULL;
    data->directions = NULL;
    data->colors = NULL;
    utils->size_map = 0;
    return ;
}