#include "cub3D.h"

void	clean_gnl(int fd, char *line)
{
	if (line)
	{	
		free(line);
		line = NULL;
	}
	if (fd > 2)
		close(fd);
}