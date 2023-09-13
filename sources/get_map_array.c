#include "cub3D.h"

int read_map(char *path)
{
	char	*line;
	int	fd;

	line = NULL;
	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (ft_dprintf(2, "Error\nThe file could not be opened\n"), FAILURE);
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		ft_dprintf(1, "%s", line);
		free(line);
	}
	close(fd);
	return (SUCCESS);
}