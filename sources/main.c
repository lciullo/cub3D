#include "cub3D.h"

int	main(int ac, char **av)
{
	t_data		data;
	t_parsing	utils;	
  
	(void)av;
	if (ac != 2)
	{
		ft_dprintf(2, "Error\nWrong number of arguments\n");
		return (FAILURE);
	}
	init_struct(&data, &utils);
	if (parsing(av[1], &data, &utils) == FAILURE)
		return (FAILURE);
	int	i = 0;
	while (i < utils.size_map)
	{
		ft_dprintf(1, "%d\n", data.len_line[i]);
		i++;
	}
	/*if (launch_mlx(&data) == FAILURE)
		return (FAILURE);*/
	return (0);
}
