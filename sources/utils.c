#include "cub3D.h"

void	init_struct_data(t_data *data)
{
	data->mlx = NULL;
	data->win = NULL;
}

void	print_error_messages(int error_code)
{
	if (error_code == MLX)
		ft_dprintf(2, RED"Error: A function from the mlx failed\n"END);
}
