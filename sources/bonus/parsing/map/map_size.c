/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_size.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lciullo <lciullo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 09:13:27 by lciullo           #+#    #+#             */
/*   Updated: 2023/10/11 11:34:41 by lciullo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	read_map(int fd, t_data *data, char *line);
static int	count_height_map(int fd, t_data *data, char *line, int map);

int	get_size_map(char *path, t_data *data, char *line)
{
	int	fd;

	fd = ft_open(path);
	if (fd == ERROR)
		return (FAILURE);
	if (read_map(fd, data, line) == FAILURE)
	{
		free_textures(data);
		return (FAILURE);
	}
	return (SUCCESS);
}

static int	read_map(int fd, t_data *data, char *line)
{
	int	map;

	map = FALSE;
	if (count_height_map(fd, data, line, map) == FAILURE)
		return (FAILURE);
	if (data->size_map == 0)
		return (FAILURE);
	if (fd > 2)
		close(fd);
	return (SUCCESS);
}

static int	count_height_map(int fd, t_data *data, char *line, int map)
{
	while (1)
	{
		line = get_next_line(fd);
		if (line && is_empty_line(line) == FALSE && map == TRUE)
		{
			clean_gnl(fd, line);
			ft_dprintf(2, "Error\nInvalid map\n");
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
	clean_gnl(fd, line);
	return (SUCCESS);
}

int	fill_len_line_array(t_data *data)
{
	int	i;

	i = 0;
	data->len_line = (int *)ft_calloc(data->size_map + 1, sizeof(int));
	if (!data->len_line)
	{
		free_textures(data);
		secure_free_array(data->map, data->size_map);
		ft_dprintf(2, "Error\nMalloc failed in fill len line array\n");
		return (FAILURE);
	}
	while (data->map[i])
	{
		data->len_line[i] = ft_strlen(data->map[i]);
		i++;
	}
	return (SUCCESS);
}
