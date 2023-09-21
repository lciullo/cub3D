#include "cub3D.h"

int	main(int ac, char **av)
{
	t_data		data;
	t_parsing	utils;	

	int	y;

	y = 0;
	(void)av;
	if (ac != 2)
	{
		ft_dprintf(2, "Error\nWrong number of arguments\n");
		return (FAILURE);
	}
	if (parsing(av[1], &data, &utils) == FAILURE)
		return (FAILURE);
	int x = 0;
	while (data.map[y])
	{
		x = 0;
		while (data.map[y][x])
		{
			ft_dprintf(1, "%c", data.map[y][x]);
			x++;
		}
		y++;
	}
	// if (launch_mlx(&data) == FAILURE)
	// 	return (FAILURE);
	return (0);
}
