#include "cub3D.h"

int is_hedge(char *line)
{
	int i;

	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] != '1' && line[i] != '0' && line[i] != ' ' && \
			line[i] != 'W' && line[i] != 'S' && line[i] != 'N' && line[i] != 'E')
			return (FALSE);
		i++;
	}
	return (TRUE);
}