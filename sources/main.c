#include "cub3D.h"

int	main(int ac, char **av)
{
	t_data		data;
	t_parsing	utils;	
	t_data	data;


	(void)av;
	(void)draw;
	if (ac != 2)
	{
		ft_dprintf(2, "Error\nWrong number of arguments\n");
		return (FAILURE);
	}
	init_struct(&data, &utils);
	if (parsing(av[1], &data, &utils) == FAILURE)
		return (FAILURE);
	/*if (launch_mlx(&data, &draw) == FAILURE)
		return (FAILURE);*/
	return (0);
}
