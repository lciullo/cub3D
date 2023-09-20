#include "cub3D.h"

void	draw_vertical_rectangle(t_draw *draw, int x, int y, int color)
{
	int	i;
	int	j;
	int	x_value;

	i = 0;
	j = 0;
	x_value = x;
	while (j < (SIZE_Y - 25))
	{
		i = 0;
		x = x_value;
		while (i < 25)
		{
			my_mlx_pixel_put(draw, x, y, color);
			x++;
			i++;
		}
		j++;
		y++;
	}
}

void	draw_horizontal_rectangle(t_draw *draw, int x, int y, int color)
{
	int	i;
	int	j;
	int	x_value;

	i = 0;
	j = 0;
	x_value = x;
	while (j < 25)
	{
		i = 0;
		x = x_value;
		while (i < SIZE_X)
		{
			my_mlx_pixel_put(draw, x, y, color);
			x++;
			i++;
		}
		j++;
		y++;
	}
}