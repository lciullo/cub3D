#include "cub3D.h"

int	main(void)
{
	t_data	data;

	if (launch_mlx(&data) == FAILURE)
		return (FAILURE);
	return (0);
}

int	launch_mlx(t_data *data)
{
	data->mlx = mlx_init();
	if (data->mlx == NULL)
		return (print_error_messages(MLX), quit_game(data), FAILURE);
	data->win = mlx_new_window(data->mlx, 1080, 1080, "cubi_rose");
	if (data->win == NULL)
		return (print_error_messages(MLX), quit_game(data), FAILURE);
	hook(data);
	mlx_loop(data->mlx);
	return (SUCCESS);
}
