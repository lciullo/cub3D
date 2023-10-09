#include "cub3D.h"

void	print_error_messages(int error_code)
{
	if (error_code == MLX)
		ft_dprintf(2, RED"Error\nA function from the mlx failed\n"END);
}
