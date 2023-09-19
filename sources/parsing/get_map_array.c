#include "cub3D.h"

int read_map(char *path, t_data *data)
{
	t_parsing	utils;
	char		*line;
	int			fd;
	int			begin;

	line = NULL;
	utils.size_map = 0;
	begin = 0;
	(void)data;
	(void)utils;
	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (ft_dprintf(2, "Error\nThe file could not be opened\n"), FAILURE);
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		while ((is_map(line) == FALSE))
		{
			if (line)
				free(line);
			line = get_next_line(fd);
			begin++;
			
		}
		if (line)
			free(line);
	}
	//ft_dprintf(1, "nb lines %d size_map %d \n", nb_lines, size_map);
	ft_dprintf(1, "begin %d\n", begin);
	close(fd);
	return (SUCCESS);
}
