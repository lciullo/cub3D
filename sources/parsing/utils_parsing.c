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
	int i;

	i = 0;
	while (line[i])
	{
		if ((line[i] != '\n') && (line[i] != ' '))
			return (FALSE);
		i++;
	}
	return (TRUE);
}

int is_map(char *line)
{
	int i;

	i = 0;
	while (line[i])
	{
		if (is_valid(line[i]) == TRUE)
			i++;
		else
			return (FALSE);
	}
	return (TRUE);
}