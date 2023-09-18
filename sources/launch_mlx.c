#include "cub3D.h"

int	launch_mlx(t_data *data)
{
	data->mlx = mlx_init();
	if (data->mlx == NULL)
		return (print_error_messages(MLX), quit_game(data), FAILURE);
	data->win = mlx_new_window(data->mlx, SIZE_X, SIZE_Y, "cubi_rose");
	if (data->win == NULL)
		return (print_error_messages(MLX), quit_game(data), FAILURE);
	generate_image(data);
	hook(data);
	mlx_loop(data->mlx);
	return (SUCCESS);
}

void	generate_image(t_data *data)
{
	t_draw	draw;

	draw.img = mlx_new_image(data->mlx, SIZE_X, SIZE_Y);
	draw.addr = mlx_get_data_addr(draw.img, &draw.bits_per_pixel, \
	&draw.line_length, &draw.endian);
	draw_frame(&draw, H_RED);
	mlx_put_image_to_window(data->mlx, data->win, draw.img, 0, 0);
	mlx_destroy_image(data->mlx, draw.img);
}
