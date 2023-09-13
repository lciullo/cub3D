#include "cub3D.h"

static int	type_file_check(char *file);

int parsing(char *file)
{
	if (type_file_check(file) == FAILURE)
		return (FAILURE);
	if (read_map(file) == FAILURE)
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
