#include "cub3D.h"
#include <stdio.h>
int read_map(char *path)
{
	char	*tmp;
	int	fd;

	tmp = NULL;
	fd = open("", O_RDONLY);
	if (fd == -1)
		return (ft_dprintf(2, "Error\nThe file could not be opened\n"), FAILURE);
	while (1)
	{
		tmp = get_next_line(fd);
		if (tmp == NULL)
			break ;
		ft_dprintf(1, "line : %s\n", tmp);
	}
	close(fd);
	return (SUCCESS);
}