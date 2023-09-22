#include "cub3D.h"

void init_struct(t_data *data, t_parsing *utils)
{
    (void)utils;
    data->map = NULL;
    data->directions = NULL;
    data->colors = NULL;
    data->len_line = 0;
    data->size_map = 0;
    return ;
}