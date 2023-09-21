#include "cub3D.h"

int fill_map(char *path, t_parsing *utils, t_data *data, char *line)
{
	int	fd;
	int	row;

	row = 0;
	fd = ft_open(path);
	if (fd == ERROR)
		return (FAILURE);
	data->map = malloc(sizeof(char **) * (utils->size_map + 1));
	if (!data->map)
		return (FAILURE);
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		while (is_map(line) == TRUE && is_empty(line) == FALSE)
		{	
			data->map[row] = ft_strdup(line);
			if (line)
				free(line);
			line = get_next_line(fd);
			row++;	
		}
		if (line)
			free(line);
	}
	data->map[row] = NULL;
	close(fd);
	return (SUCCESS);
}