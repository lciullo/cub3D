#include "cub3D.h"

void	draw_frame(t_draw *draw, int color)
{
	draw_horizontal_rectangle(draw, 0, 0, color);
	draw_horizontal_rectangle(draw, 0, (SIZE_Y - 25), color);
	draw_vertical_rectangle(draw, 0, 25, color);
	draw_vertical_rectangle(draw, (SIZE_X - 25), 25, color);
}