#include "cub3D.h"

int read_map(char *path)
{
	char	*tmp;
	int	fd;

	tmp = NULL;
	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (ft_dprintf(2, "Error\nThe file could not be opened\n"), FAILURE);
	while (1)
	{
		tmp = get_next_line(fd);
		if (tmp == NULL)
			break ;
		ft_dprintf(1, "%s\n", tmp);
		free(tmp);
	}
	close(fd);
	return (SUCCESS);
}