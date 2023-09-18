#include "cub3D.h"
#include "stdio.h"

int	main(int ac, char **av)
{
	t_data	data;

	(void)av;
	if (ac != 2)
	{
		ft_dprintf(2, "Error\nWrong number of arguments\n");
		return (FAILURE);
	}
	/*if (parsing(av[1]) == FAILURE)
		return (FAILURE);*/
	if (launch_mlx(&data) == FAILURE)
		return (FAILURE);
	return (0);
}
