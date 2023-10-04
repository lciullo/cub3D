/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_size.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lciullo <lciullo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 09:13:27 by lciullo           #+#    #+#             */
/*   Updated: 2023/10/04 16:00:12 by lciullo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	read_map(int fd, t_data *data, char *line);

int	get_size_map(char *path, t_data *data, char *line)
{
	int	fd;

	fd = ft_open(path);
	if (fd == ERROR)
		return (FAILURE);
	if (read_map(fd, data, line) == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}

static int read_map(int fd, t_data *data, char *line)
{
	int	map;

	map = FALSE;
	while (1)
	{
		line = get_next_line(fd);
		if (line && is_empty_line(line) == FALSE && map == TRUE)
		{
			if (line)
				free(line);
			ft_dprintf(2, "Error\nDon't put empty line on map\n");
			close(fd);
			return (FAILURE);
		}
		if (line == NULL)
			break ;
		while ((is_map(line) == TRUE) && is_empty_line(line) == FALSE)
		{
			map = TRUE;
			if (line)
				free(line);
			line = get_next_line(fd);
			data->size_map++;
		}
		if (line)
			free(line);
	}
	close(fd);
	return (SUCCESS);
}


int	fill_len_line_array(t_data *data)
{
	int	i;

	i = 0;
	data->len_line = malloc((sizeof(int **)) * (data->size_map + 1));
	if (!data->len_line)
		return (FAILURE);
	while (data->map[i])
	{
		data->len_line[i] = ft_strlen(data->map[i]);
		i++;
	}
	return (SUCCESS);
}
