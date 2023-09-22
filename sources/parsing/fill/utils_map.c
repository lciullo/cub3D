#include "cub3D.h"

static int read_map(int fd, t_parsing *utils, char *line);
static int count_map_size(t_parsing *utils, int fd, char *line);

int is_map(char *line)
{
	int i;

	i = 0;
	if (!line)
		return (FALSE);
	while (line[i])
	{
		if (is_valid(line[i]) == TRUE)
			i++;
		else
			return (FALSE);
	}
	return (TRUE);
}

int get_size_map(char *path, t_parsing *utils, char *line)
{
    int	fd;

	fd = ft_open(path);
	if (fd == ERROR)
		return (FAILURE);
    if (read_map(fd, utils, line) == FAILURE)
        return (FAILURE);
    return (SUCCESS);
}

static int read_map(int fd, t_parsing *utils, char *line)
{
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		while ((is_map(line) == TRUE))
		{
			if (count_map_size(utils, fd, line) == FAILURE)
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

static int count_map_size(t_parsing *utils, int fd, char *line)
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

#include "stdio.h"

int	count_line(t_data *data, t_parsing *utils)
{
	int i;

	i = 0;
	data->len_line = malloc((sizeof (int **
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	)) * (utils->size_map + 1));
	if (!data->len_line)
		return (FAILURE);
	while (data->map[i])
	{
		data->len_line[i] = ft_strlen(data->map[i]);
		i++;
	}
	//data->len_line[i] = '\0';
	return (SUCCESS);
}