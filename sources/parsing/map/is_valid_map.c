#include "cub3D.h"

static void	count_nb_player(t_data *data, t_parsing *utils);
char **ft_copy_map(t_data *data);

int	check_around(int y, int x, char **copy)
{
	if (y == 0) // check up 
		return (FAILURE);
	if (x == 0) //check left
		return (FAILURE);
	
	
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

char **ft_copy_map(t_data *data)
{
	int	y;
	char **copy_map;
	

	y = 0;
	copy_map = malloc(sizeof(char *) * (data->size_map + 1));
	if (!copy_map)
		return (NULL);
	while (data->map[y])
	{
		copy_map[y] = ft_strdup(data->map[y]);
		if (!copy_map[y])
			return (NULL);
		y++;
	}
	copy_map[y] = NULL;
	return (copy_map);
}

/*static int	four_sides_check(t_data *data)
{

}*/

int is_one_player(t_data *data, t_parsing *utils)
{
	count_nb_player(data, utils);
	if (utils->nb_player != 1)
	{	
		ft_dprintf(2, "Error\nYou must add one player\n");
		return (FAILURE);
	}
	return (SUCCESS);
}

static void	count_nb_player(t_data *data, t_parsing *utils)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	while (data->map[y])
	{
		x = 0;
		while (data->map[y][x])
		{
			if (data->map[y][x] == 'N' || data->map[y][x] == 'S' || \
					data->map[y][x] == 'E' || data->map[y][x] == 'W')
				utils->nb_player++;
			x++;
		}
		y++;
	}
}