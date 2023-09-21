#include "cub3D.h"

int is_valid(char c)
{
	if ((c == '1') || (c == '0') || (c == ' ') || (c == 'W') || \
		 (c == 'S') || (c == 'N') || (c == 'E') || (c == '\n'))
		return (TRUE);
	return (FALSE);
}

int	is_empty(char *line)
{
	int 	i;
	size_t	count;

	i = 0;
	count = 0;
	while (line[i])
	{
		if ((line[i] == '\n') || (line[i] == ' '))
			count++;
		i++;
	}
	if (ft_strlen(line) == count)
		return (TRUE);
	return (FALSE);
}

int	ft_open(char *path)
{
	int fd;

	fd = open(path, O_RDONLY);
	if (fd == ERROR)
		return (ft_dprintf(2, "Error\nThe file could not be opened\n"), ERROR);
	return (fd);
}