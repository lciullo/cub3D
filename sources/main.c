#include "cub3D.h"
#include "stdio.h"

int	main(int ac, char **av)
{
	t_data	data;

	(void)data;
	if (ac != 2)
		ft_dprintf(2, "Error\nWrong number of arguments\n");
	if (parsing(av[1]) == FAILURE)
		return (FAILURE);
	/*if (launch_mlx(&data) == FAILURE)
		return (FAILURE);*/
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
