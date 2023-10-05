#include "cub3D.h"

static void	free_parsing(t_parsing *utils, t_data *data);

int	main(int ac, char **av)
{
	t_data		data;
	t_parsing	utils;	

	data.angle = 0;
	if (ac != 2)
	{
		ft_dprintf(2, "Error\nWrong number of arguments\n");
		return (FAILURE);
	}
	init_struct(&data, &utils);
	if (parsing(av[1], &data, &utils) == FAILURE)
		return (FAILURE);
	free_parsing(&utils, &data);
	/*if (launch_mlx(&data) == FAILURE)
		return (FAILURE);*/
	return (0);
}

static void	free_parsing(t_parsing *utils, t_data *data)
{
	int	i;

	i = 0;
	while (i < data->size_map)
	{
		free(data->map[i]);
		i++;
	}
	free(data->map[i]);
	data->map = NULL;
	free(data->len_line);
	if (utils->north_path)
		free(utils->north_path);
	if (utils->south_path)
		free(utils->south_path);
	if (utils->west_path)
		free(utils->west_path);
	if (utils->east_path)
		free(utils->east_path);
	if (utils->color_c_path)
		free(utils->color_c_path);
	if (utils->color_f_path)
		free(utils->color_f_path);
}
