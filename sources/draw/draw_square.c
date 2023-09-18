#include "cub3D.h"

void	draw_square(t_draw *draw, int x, int y, int color, int size)
{
	int	i;
	int	j;
	int	x_value;

	i = 0;
	j = 0;
	x_value = x;
	while (j < size)
	{
		i = 0;
		x = x_value;
		while (i < size)
		{
			my_mlx_pixel_put(draw, x, y, color);
			x++;
			i++;
		}
		j++;
		y++;
	}
}