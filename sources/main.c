#include "cub3D.h"

int	main(int ac, char **av)
{
	t_data	data;
	char **tmp_map;

	tmp_map = NULL;
	(void)av;
	if (ac != 2)
	{
		ft_dprintf(2, "Error\nWrong number of arguments\n");
		return (FAILURE);
	}
	/*if (parsing(av[1]) == FAILURE)
		return (FAILURE);*/
	int i = 0;
	tmp_map = make_map(av[1]);
	while (tmp_map[i])
	{
		ft_dprintf(1, "%s\n", tmp_map[i]);
		i++;
	}
	if (launch_mlx(&data, &draw) == FAILURE)
		return (FAILURE);
	return (0);
}
