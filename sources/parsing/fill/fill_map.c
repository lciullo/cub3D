#include "cub3D.h"


int ft_strnlen(const char *s1)
{
	int i;

	i = 0;
	while (s1[i] != '\0' && s1[i] != '\n')
	{
		i++;
	}
	return (i);	
}

char	*ft_strnndup(const char *s1)
{
	char	*dest;
	int		len;
	int		i;

	i = 0;
	len = ft_strnlen(s1);
	dest = malloc(sizeof(char) * (len + 1));
	if (!(dest))
		return (0);
	while (s1[i] != '\0' && s1[i] != '\n')
	{
		dest[i] = s1[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}



int fill_map(char *path, t_data *data, char *line)
{
	int	fd;
	int	row;

	row = 0;
	fd = ft_open(path);
	if (fd == ERROR)
		return (FAILURE);
	data->map = malloc(sizeof(char **) * (data->size_map + 1));
	if (!data->map)
		return (FAILURE);
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		while (is_map(line) == TRUE && is_empty(line) == FALSE)
		{	
			data->map[row] = ft_strnndup(line);
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