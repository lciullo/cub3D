#include "cub3D.h"

int read_map(char *path)
{
    char    *tmp;
    int     fd;
    

    tmp = NULL;
    fd = open(path, O_RDONLY);
	if (fd == FAILURE)
		return (ft_dprintf(2, "Error\nThe file could not be opened\n"), FAILURE);
    //ft_dprintf(2, "line : %s\n", tmp);
    while (1)
	{
		tmp = get_next_line(fd);
        //ft_dprintf(2, "line : %s\n", tmp);
		if (tmp == NULL)
			break ;
		free(tmp);
	}
	close(fd);
    return (SUCCESS);
}