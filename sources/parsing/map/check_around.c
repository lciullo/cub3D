#include "cub3D.h"

static int check_up(t_data *data, int y, int x, char **copy);

int	check_around(t_data *data, int y, int x, char **copy)
{
	if (check_up(data, y, x, copy) == FAILURE)
		return (FAILURE);
	(void)copy;
	return (SUCCESS);
}

static int check_up(t_data *data, int y, int x, char **copy)
{
	if (y == 0 || x >= (data->len_line[y - 1] - 1))
		return (FAILURE);
	if (copy[y - 1][x] == '1')
		return (SUCCESS);
	if (copy[y - 1][x] != '0')
		return (FAILURE);
	return (SUCCESS);
}