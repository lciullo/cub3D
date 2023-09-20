#include "cub3D.h"

static char	*delete_last_col(char *line)
{
	size_t	i;

	i = 0;
	while (line[i])
		i++;
	if (i == 0)
		line[0] = '\0';
	else
		line[i - 1] = '\0';
	return (line);
}

static char	*tmp(ssize_t cursor, int fd, char *buffer, char *line)
{
	while (cursor == 1)
	{
		cursor = read(fd, buffer, 1);
		buffer[1] = '\0';
		line = ft_strjoin(line, buffer);
		if (ft_strlen(line) == 0)
		{
			free(line);
			return (ft_dprintf(2,"ERROR\nEmpty map\n"), NULL);
		}
	}
	if (cursor == -1)
	{
		ft_dprintf(2,"ERROR\nRead error\n");
		free (line);
		exit (0);
	}
	line = delete_last_col(line);
	return (line);
}

char	**make_map(char *file)
{
	char	*line;
	char	**map;
	char	buffer[2];
	int		fd;
	ssize_t	cursor;

	cursor = 1;
	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		return (ft_dprintf(2,"ERROR\nThe file could not be opened\n"), NULL);
	}
	line = malloc(sizeof(char));
	if (!line)
		return (ft_dprintf(2,"ERROR\nA malloc fail\n"), NULL);
	line[0] = '\0';
	line = tmp(cursor, fd, buffer, line);
	if (line == NULL)
		exit (0);
	map = ft_split(line, '\n');
	if (!map)
		return (ft_dprintf(2,"ERROR\nA malloc fail\n"), NULL);
	return (free(line), map);
}