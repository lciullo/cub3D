#include "cub3D.h"

static int init_image(t_data *data, t_draw *draw);

int	render_next_frame(t_data *data)
{
	t_draw	draw;

	if (init_image(data, &draw) == FAILURE)
		return (FAILURE);
	raycasting(data, &draw);
	mini_map(data, &draw);
	mlx_put_image_to_window(data->mlx, data->win, draw.img, 0, 0);
	mlx_destroy_image(data->mlx, draw.img);
	mlx_do_sync(data->mlx);
	return (SUCCESS);
}

static int init_image(t_data *data, t_draw *draw)
{
	draw->img = mlx_new_image(data->mlx, SIZE_X, SIZE_Y);
	if (draw->img == NULL)
		return (print_error_mlx(), quit_game(data), FAILURE);
	draw->addr = mlx_get_data_addr(draw->img, &draw->bits_per_pixel, \
	&draw->line_length, &draw->endian);
	if (draw->addr == NULL)
		return (print_error_mlx(), quit_game(data), FAILURE);
	return (SUCCESS);
}