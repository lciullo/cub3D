/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lciullo <lciullo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 09:09:47 by lciullo           #+#    #+#             */
/*   Updated: 2023/10/09 11:36:28 by lciullo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	len_of_line(const char *s1);
static char	*copy_line(const char *s1);
static int	copy_map(t_data *data, char *line, int fd, int y);
static int	is_map_at_end(char *line);

int	fill_map(char *path, t_data *data, char *line)
{
	int	y;
	int	fd;

	y = 0;
	fd = ft_open(path);
	if (fd == ERROR)
		return (FAILURE);
	data->map = malloc(sizeof(char **) * (data->size_map));
	if (!data->map)
		return (FAILURE);
	if (copy_map(data, line, fd, y) == FAILURE)
		return (FAILURE);
	close(fd);
	return (SUCCESS);
}

static int	copy_map(t_data *data, char *line, int fd, int y)
{
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		while (is_map(line) == TRUE && is_empty_line(line) == FALSE)
		{
			data->map[y] = copy_line(line);
			if (line)
				free(line);
			line = get_next_line(fd);
			if (is_map_at_end(line) == FAILURE)
				return (FAILURE);
			y++;
		}
		if (line)
			free(line);
	}
	data->map[y] = NULL;
	return (SUCCESS);
}

static int	is_map_at_end(char *line)
{
	if (line)
	{
		if (is_map(line) == FALSE)
		{
			if (line)
				free(line);
			line = NULL;
			ft_dprintf(2, "Error\nInvalid Map\n");
			return (FAILURE);
		}
	}
	return (SUCCESS);
}

static int	len_of_line(const char *s1)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' && s1[i] != '\n')
	{
		i++;
	}
	return (i);
}

static char	*copy_line(const char *s1)
{
	char	*dest;
	int		len;
	int		i;

	i = 0;
	len = len_of_line(s1);
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
