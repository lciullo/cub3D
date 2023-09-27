#include "cub3D.h"

static int check_up(t_data *data, int y, int x, char **copy);
static int check_down(t_data *data, int y, int x, char **copy);
static int check_left(int y, int x, char **copy);
static int check_right(t_data *data, int y, int x, char **copy);

int	check_around(t_data *data, int y, int x, char **copy)
{
	if (check_up(data, y, x, copy) == FAILURE)
		return (FAILURE);
	if (check_down(data, y, x, copy) == FAILURE)
		return (FAILURE);
	if (check_left(y, x, copy) == FAILURE)
		return (FAILURE);
	if (check_right(data, y, x, copy) == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}

static int check_up(t_data *data, int y, int x, char **copy)
{
	if (y == 0)
		return (FAILURE);
	if (x >= (data->len_line[y - 1] - 1))
		return (FAILURE);
	if (copy[y - 1][x] == '1')
		return (SUCCESS);
	if (copy[y - 1][x] != '0')
		return (FAILURE);
	return (SUCCESS);
}

static int check_down(t_data *data, int y, int x, char **copy)
{
	if (y >= data->len_line[y]) //last line
		return (FAILURE);
	if (x >= (data->len_line[y + 1] - 1)) //check
		return (FAILURE);
	if (copy[y + 1][x] == '1')
		return (SUCCESS);
	if (copy[y + 1][x] != '0')
		return (FAILURE);
	return (SUCCESS);
}

static int check_left(int y, int x, char **copy)
{
	if (x == 0) //is in left top corner 
		return (FAILURE);
	if (copy[y][x - 1] == '1')
		return (SUCCESS);
	if (copy[y][x - 1] != '0')
		return (FAILURE);
	return (SUCCESS);
}

static int check_right(t_data *data, int y, int x, char **copy)
{
	if (x >= (data->len_line[y] - 1)) //is 
		return (FAILURE);
	if (copy[y][x + 1] == '1')
		return (SUCCESS);
	if (copy[y][x + 1] != '0')
		return (FAILURE);
	return (SUCCESS);
}