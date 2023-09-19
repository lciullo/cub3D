#include "cub3D.h"

int read_map(char *path, t_data *data)
{
	char	*line;
	int	fd;
	int	i;
	int nb_lines;
	int size_map;

	line = NULL;
	nb_lines = 0;
	size_map = 0;
	(void)data;
	fd = open(path, O_RDONLY);
	i = TRUE;
	if (fd == -1)
		return (ft_dprintf(2, "Error\nThe file could not be opened\n"), FAILURE);
	while (i == TRUE)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		if (is_hedge(line) == TRUE)
		{
			size_map++;
			ft_dprintf(1, "size_map %d \n", size_map);
			ft_dprintf(1, "line %s \n", line);
		}
		nb_lines++;
		free(line);
	}
	//ft_dprintf(1, "nb lines %d size_map %d \n", nb_lines, size_map);
	close(fd);
	return (SUCCESS);
}
