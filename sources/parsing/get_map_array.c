#include "cub3D.h"

static int get_size_map(char *path, t_parsing *utils, char *line);
static int get_map_array(char *path, t_parsing *utils, char **map, char *line);
static int read_for_map(t_parsing *utils, int fd, char *line);

int parse_map(char *path, t_parsing *utils, t_data *data)
{
	char *line;

	line = NULL;
	if (get_size_map(path, utils, line) == FAILURE)
		return (FAILURE);
	if (get_map_array(path, utils, data->map, line) == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}

static int get_size_map(char *path, t_parsing *utils, char *line)
{
	int	fd;

	fd = ft_open(path);
	if (fd == ERROR)
		return (FAILURE);
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		while ((is_map(line) == TRUE))
		{
			if (read_for_map(utils, fd, line) == FAILURE)
				return (FAILURE);
			if (line)
				free(line);
			line = get_next_line(fd);
			utils->size_map++;	
		}
		if (line)
			free(line);
	}
	close(fd);
	return (SUCCESS);
}

static int read_for_map(t_parsing *utils, int fd, char *line)
{
	if (utils->size_map == 0 && is_empty(line) == TRUE)
		utils->size_map--;
	if ((utils->size_map != 0 && utils->size_map != -1) && is_empty(line) == TRUE)
	{
		if (line)
			free(line);
		ft_dprintf(2, "Error\nDon't put empty line on map\n");
		close(fd);
		return (FAILURE);
	}
	return (SUCCESS);
}

static int get_map_array(char *path, t_parsing *utils, char **map, char *line)
{
	int	fd;
	int	row;

	row = 0;
	fd = ft_open(path);
	if (fd == ERROR)
		return (FAILURE);
	map = malloc(sizeof(char *) * (utils->size_map + 1));
	if (!map)
		return (FAILURE);
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		while (is_map(line) == TRUE && is_empty(line) == FALSE)
		{	
			map[row] = ft_strdup(line);
			if (line)
				free(line);
			line = get_next_line(fd);
			row++;	
		}
		if (line)
			free(line);
	}
	map[row] = NULL;
	int i = 0;
	while (map[i])
	{
		ft_dprintf(1, "%s", map[i]);
		i++;
	}
	ft_dprintf(1, "\n%s", map[i]);
	//ft_dprintf(1, "\ntest\n in loop row %d | map[row] %s\n", row, map[0]);
	close(fd);
	return (SUCCESS);
}