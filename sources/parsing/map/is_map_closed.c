#include "cub3D.h"

int	move_on_map(t_data *data, int y, int x, char **copy)
{
	(void)y;
	(void)x;
	(void)copy;
	if (check_around(data, y, x, copy) == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}

int	is_map_closed(t_data *data)
{
	char	**copy_map;

	copy_map = ft_copy_map(data);
	if (!copy_map)
		return (FAILURE);
	if (move_on_map(data, data->y_pers, data->x_pers, copy_map) == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}