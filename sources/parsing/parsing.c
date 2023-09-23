#include "cub3D.h"

static int	type_file_check(char *file);

int parsing(char *file, t_data *data, t_parsing *utils)
{
	if (type_file_check(file) == FAILURE)
		return (FAILURE);
	if (parse_map(file, utils, data) == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}

static int	type_file_check(char *file)
{
	size_t	len;

	len = ft_strlen(file);
	if (file[len - 1] != 'b' || file[len - 2] != 'u' || file[len - 3] != 'c'\
		|| file[len - 4] != '.')
	{
		ft_dprintf(2, "Error\nMap name must be finished by .cub\n");
		return (FAILURE);
	}
	return (SUCCESS);
}

int parse_map(char *path, t_parsing *utils, t_data *data)
{
	char *line;

	line = NULL;
	(void)utils;
	if (get_size_map(path, data, line) == FAILURE)
		return (FAILURE);
	if (fill_map(path, data, line) == FAILURE)
		return (FAILURE);
	if (count_line(data) == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}