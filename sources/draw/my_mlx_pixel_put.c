#include "cub3D.h"

void    my_mlx_pixel_put(t_draw *draw, int x, int y, int color)
{
    ((int *)draw->addr)[y * (draw->line_length >> 2) + x] = color;
}