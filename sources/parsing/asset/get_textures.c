#include "cub3D.h"

static void	skip_white_space(char *line);

int read_map_textures(char *path, t_data *data)
{
	char        *line;
	int            fd;

	line = NULL;
	(void)data;
	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (ft_dprintf(2, "Error\nThe file could not be opened\n"), FAILURE);
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		if (ft_strchr(line, 'W') && ft_strchr(line, 'E'))
		{
			skip_white_space(line);
		}
		free(line);
	}
	close(fd);
	return (SUCCESS);
}


static void ft_copy(char c, int index, char *texture)
{
	texture[index] = c;
}

static void	skip_white_space(char *s)
{
	int 	i;
	int		len;
	char 	*texture;

	i = 0;
	len = 0;
	texture = NULL;
	while (s[i] != '\0' && s[i] != '\n')
	{
		if ((s[i] != '\0') && (s[i] == ' ' || s[i] == '\t' || s[i] == '\v' || s[i] == '\r'))
			i++;
		else
		{	
			len++;
			i++;
		}
	}
	texture = malloc(sizeof(char) * (len + 1));
	if (!texture)
		return ;
	i = 0;
	int index = 0;
	while (s[i] != '\0' && s[i] != '\n')
	{
		if ((s[i] == ' ' || s[i] == '\t' || s[i] == '\v' || s[i] == '\r'))
			i++;
		else
		{	
			ft_copy(s[i], index, texture);
			index++;
			i++;
		}
	}
	texture[index] = '\0';
}