#include "cub3D.h"
#include <stdio.h>

/*g->smap->map_cpy[y][x] = '1';
	if (check_around(g, x, y) == OPEN)
		return (OPEN);
	if (check_up(g->smap, x, y) == 0 && backtracking(g, y - 1, x) == OPEN)
		return (OPEN);
	if (check_down(g->smap, x, y) == 0 && backtracking(g, y + 1, x) == OPEN)
		return (OPEN);
	if (check_right(g->smap, x, y) == 0 && backtracking(g, y, x + 1) == OPEN)
		return (OPEN);
	if (check_left(g->smap, x, y) == 0 && backtracking(g, y, x - 1) == OPEN)
		return (OPEN);
	return (0);
*/

int	move_on_map(t_data *data, int y, int x, char **copy)
{
	copy[y][x] = '1';
	if (check_around(data, y, x, copy) == FAILURE)
		return (FAILURE);
	if (check_up(data, y, x, copy) == SUCCESS && move_on_map(data, y - 1, x, copy) == FAILURE)
		return (FAILURE);
	if (check_down(data, y, x, copy) == SUCCESS && move_on_map(data, y + 1, x, copy) == FAILURE)
		return (FAILURE);
	if (check_right(data, y, x, copy) == SUCCESS && move_on_map(data, y, x + 1, copy) == FAILURE)
		return (FAILURE);
	if (check_left(y, x, copy) == SUCCESS && move_on_map(data, y, x - 1, copy) == FAILURE)
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
	{	
		ft_dprintf(2, "Error\nMap isn't closed\n");
		return (FAILURE);
	}
	return (SUCCESS);
}