#include "cub3D.h"

int	check_around(int y, int x, char **copy)
{
	if (y == 0) // check up 
		return (FAILURE);
	if (x == 0) //check left
		return (FAILURE);
	
	(void)copy;
	return (SUCCESS);
}

int	move_on_map(int y, int x, char **copy)
{
	(void)y;
	(void)x;
	(void)copy;
	if (check_around(y, x, copy) == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}

int	is_map_closed(t_data *data)
{
	char	**copy_map;

	copy_map = ft_copy_map(data);
	if (!copy_map)
		return (FAILURE);
	if (move_on_map(data->y_pers, data->x_pers, copy_map) == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}