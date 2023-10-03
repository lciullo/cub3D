#include "cub3D.h"

int	launch_mlx(t_data *data)
{
	data->gap = 10;
	data->px_map = (data->xf_p * SQUARE_SIZE);
	data->py_map = (data->yf_p * SQUARE_SIZE);
	data->angle = 0;
	find_direction(data);
	data->mlx = mlx_init();
	if (data->mlx == NULL)
		return (print_error_messages(MLX), quit_game(data), FAILURE);
	data->win = mlx_new_window(data->mlx, SIZE_X, SIZE_Y, "cubi_rose");
	if (data->win == NULL)
		return (print_error_messages(MLX), quit_game(data), FAILURE);
	hook(data);
	return (SUCCESS);
}

void	generate_image(t_data *data)
{
	t_draw	map;

	map.img = mlx_new_image(data->mlx, SIZE_X, SIZE_Y);
	map.addr = mlx_get_data_addr(map.img, &map.bits_per_pixel, \
	&map.line_length, &map.endian);
	mini_map(data, &map);
	mlx_put_image_to_window(data->mlx, data->win, map.img, 0, 0);
	mlx_destroy_image(data->mlx, map.img);
}

int	render_next_frame(t_data *data)
{
	generate_image(data);
	mlx_do_sync(data->mlx);
	return (0);
}
