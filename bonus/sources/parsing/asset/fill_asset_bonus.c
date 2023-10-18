/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_asset_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lciullo <lciullo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 09:17:32 by lciullo           #+#    #+#             */
/*   Updated: 2023/10/18 16:15:10 by lciullo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

static int	get_texture(char *line, t_data *data);
static	int	find_asset(char *line, t_parsing *utils, t_data *data);
static	int	store_direction(char *texture, t_data *data);
static int	get_color(char *s, t_parsing *utils);

int	read_to_get_asset(char *path, t_parsing *utils, t_data *data)
{
	char	*line;
	int		fd;

	line = NULL;
	fd = open(path, O_RDONLY);
	if (fd == ERROR)
		return (ft_dprintf(2, "Error\nThe file couldn't be opened\n"), FAILURE);
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		if (find_asset(line, utils, data) == FAILURE)
		{
			clean_gnl(fd, line);
			return (FAILURE);
		}
		if (line)
			free(line);
	}
	clean_gnl(fd, line);
	return (SUCCESS);
}

static	int	find_asset(char *line, t_parsing *utils, t_data *data)
{
	if ((ft_strchr(line, 'W') && ft_strchr(line, 'E')) || \
		(ft_strchr(line, 'N') && ft_strchr(line, 'O')) || \
		(ft_strchr(line, 'S') && ft_strchr(line, 'O')) || \
		(ft_strchr(line, 'E') && ft_strchr(line, 'A')))
	{
		if (get_texture(line, data) == FAILURE)
		{
			free_asset(utils, data);
			return (FAILURE);
		}
	}
	else if (ft_strchr(line, 'C') || ft_strchr(line, 'F'))
	{
		if (get_color(line, utils) == FAILURE)
		{
			ft_dprintf(2, "Error\nMalloc failed in get_color\n");
			free_asset(utils, data);
			return (FAILURE);
		}
	}
	return (SUCCESS);
}

static int	get_texture(char *line, t_data *data)
{
	char	*texture;

	texture = malloc(sizeof(char) * (asset_line_len(line) + 1));
	if (!texture)
	{
		ft_dprintf(2, "Error\nMalloc failed in get_texture\n");
		return (FAILURE);
	}
	texture = copy_asset(texture, line);
	if (store_direction(texture, data) == FAILURE)
	{
		free_texture(texture);
		ft_dprintf(2, "Error\nMalloc failed in store_texture\n");
		return (FAILURE);
	}
	free_texture(texture);
	return (SUCCESS);
}

static int	get_color(char *s, t_parsing *utils)
{
	char	*texture;

	texture = malloc(sizeof(char) * (asset_line_len(s) + 1));
	if (!texture)
		return (FAILURE);
	texture = copy_asset(texture, s);
	if (ft_strchr(s, 'C'))
	{
		utils->color_c_path = ft_substr(texture, 1, ft_strlen(texture));
		if (!utils->color_c_path)
			return (free_texture(texture), FAILURE);
	}
	else if (ft_strchr(s, 'F'))
	{
		utils->color_f_path = ft_substr(texture, 1, ft_strlen(texture));
		if (!utils->color_f_path)
			return (free_texture(texture), FAILURE);
	}
	free_texture(texture);
	return (SUCCESS);
}

static	int	store_direction(char *texture, t_data *data)
{
	if (texture && texture[0] == 'N')
	{
		data->north_path = ft_substr(texture, 2, ft_strlen(texture));
		if (!data->north_path)
			return (FAILURE);
	}
	if (texture && texture[0] == 'S')
	{
		data->south_path = ft_substr(texture, 2, ft_strlen(texture));
		if (!data->south_path)
			return (FAILURE);
	}
	if (texture && texture[0] == 'E')
	{
		data->east_path = ft_substr(texture, 2, ft_strlen(texture));
		if (!data->east_path)
			return (FAILURE);
	}
	if (texture && texture[0] == 'W')
	{
		data->west_path = ft_substr(texture, 2, ft_strlen(texture));
		if (!data->west_path)
			return (FAILURE);
	}
	return (SUCCESS);
}
